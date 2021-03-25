t = int(input())

for _ in range(t):

    nmx = input().split(" ")

    n = int(nmx[0])
    m = int(nmx[1])
    x = int(nmx[2])

    r = ((x-1) % n)
    c = (x -1) // n

    print(r * m + c + 1)