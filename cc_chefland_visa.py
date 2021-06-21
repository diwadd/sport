t = int(input())


for _ in range(t):

    data = input().split(" ")

    x1 = int(data[0])
    x2 = int(data[1])
    y1 = int(data[2])
    y2 = int(data[3])
    z1 = int(data[4])
    z2 = int(data[5])

    if x2 >= x1 and y2 >= y1 and z2 <= z1:
        print("YES")
    else:
        print("NO")