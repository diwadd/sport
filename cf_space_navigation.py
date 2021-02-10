

t = int(input())

for _ in range(t):

    pxpy = input().split(" ")
    px = int(pxpy[0])
    py = int(pxpy[1])

    seq = input()

    rx = 0
    lx = 0
    uy = 0
    dy = 0
    for s in seq:
        if px > 0 and s == "R":
            rx += 1
        if px < 0 and s == "L":
            lx -= 1
        if py > 0 and s == "U":
            uy += 1
        if py < 0 and s == "D":
            dy -= 1

    is_x_ok = False
    is_y_ok = False
    if (px < 0 and lx <= px) or (px > 0 and rx >= px) or px == 0:
        is_x_ok = True

    if (py < 0 and dy <= py) or (py > 0 and uy >= py) or py == 0:
        is_y_ok = True

    if is_x_ok == True and is_y_ok == True:
        print("YES")
    else:
        print("NO")