import math

t = int(input())

for _ in range(t):

    nehabc = input().split(" ")
    n = int(nehabc[0])
    e = int(nehabc[1])
    h = int(nehabc[2])
    a = int(nehabc[3])
    b = int(nehabc[4])
    c = int(nehabc[5])

    minimal_price = math.inf
    for z in range(0, n+1):

        new_e = e - z
        new_h = h - z

        if new_e < 0 or new_h < 0:
            continue

        x = math.floor(new_e / 2)
        y = math.floor(new_h / 3)

        if x + y + z < n:
            continue

        total_price_all = c*z

        new_n = n - z
        if a < b and new_n > 0:
            total_price_all += a*min(x, new_n)
            new_n = max(0, new_n - x)

            total_price_all += b*min(y, new_n)
            new_n = max(0, new_n - y)
        else:
            total_price_all += b*min(y, new_n)
            new_n = max(0, new_n - y)

            total_price_all += a*min(x, new_n)
            new_n = max(0, new_n - x)

        if total_price_all < minimal_price:
            minimal_price = total_price_all


    if minimal_price < math.inf:
        print(minimal_price)
    else:
        print("-1")


