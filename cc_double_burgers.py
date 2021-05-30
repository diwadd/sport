t = int(input())

MAX_N = 64
divs = [2**i-1 for i in range(MAX_N)]

for _ in range(t):
    xy = input().split(" ")

    x = int(xy[0])
    y = int(xy[1])

    if y % x != 0:
        print(-1)
        continue

    z = y // x

    res = 0
    for i in range(len(divs)-1, -1, -1):
        d = divs[i]
        if z >= d:
            z -= d
            if z != 0:
                res += (i + 1)
            else:
                res += i

    if z == 0:
        print(res)
    else:
        print(-1)