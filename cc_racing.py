t = int(input())


for _ in range(t):

    xrm = input().split(" ")
    x = int(xrm[0])
    r = int(xrm[1])*60
    m = int(xrm[2])*60

    if r > m:
        print("NO")
    elif x >= r:
        print("YES")
    else:

        n = r // x

        needed_time = n * x + (n - 1) * x
        # print(f"n: {n} needed_time: {needed_time}")

        needed_time += max(0, 2*(r - n * x))
        # print(f"-> needed_time: {needed_time}")

        if needed_time <= m:
            print("YES")
        else:
            print("NO")