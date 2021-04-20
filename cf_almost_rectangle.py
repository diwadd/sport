t = int(input())

for _ in range(t):

    n = int(input())

    grid = [None for _ in range(n)]

    for i in range(n):
        grid[i] = input()
    
    points = []

    for i in range(n):
        for j in range(n):
            if grid[i][j] == "*":
                points.append([i, j])

    p1_x = points[0][0]
    p1_y = points[0][1]

    p2_x = points[1][0]
    p2_y = points[1][1]

    p3_x = None
    p3_y = None

    p4_x = None
    p4_y = None

    if p1_x == p2_x:

        p3_y = p1_y
        p4_y = p2_y

        if p1_x - 1 >= 0:
            p3_x = p1_x - 1
        elif p1_x + 1 <= n-1:
            p3_x = p1_x + 1

        p4_x = p3_x
    
    elif p1_y == p2_y:

        p3_x = p1_x
        p4_x = p2_x

        if p1_y - 1 >= 0:
            p3_y = p1_y - 1
        elif p1_y + 1 <= n-1:
            p3_y = p1_y + 1

        p4_y = p3_y

    else:

        p3_x = p1_x
        p3_y = p2_y

        p4_x = p2_x
        p4_y = p1_y

    points.append([p3_x, p3_y])
    points.append([p4_x, p4_y])

    for i in range(n):
        for j in range(n):

            if [i, j] in points:
                print("*", end="")
            else:
                print(".", end="")
        print()



