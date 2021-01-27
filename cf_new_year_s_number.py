t = int(input())

for _ in range(t):

    n = int(input())

    y = 2020
    m = n // y
    b = n % y

    if b <= m:
        print("YES")
    else:
        print("NO")