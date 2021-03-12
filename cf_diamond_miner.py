import math

t = int(input())

for _ in range(t):

    n = int(input())

    miners = []
    diamonds = []
    for _ in range(2*n):
        xy = input().split(" ")
        x = int(xy[0])
        y = int(xy[1])

        if x == 0:
            miners.append(abs(y))
        elif y == 0:
            diamonds.append(abs(x))

    miners.sort()
    diamonds.sort()

    d = 0.0
    for m in range(len(miners)):
        mx = 0
        my = miners[m]

        dx = diamonds[m]
        dy = 0
        
        d += math.sqrt( (mx-dx)*(mx-dx) + (my-dy)*(my-dy) )

    print(d)

