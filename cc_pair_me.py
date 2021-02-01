t = int(input())

for _ in range(t):
    xyz = input().split(" ")
    x = int(xyz[0])
    y = int(xyz[1])
    z = int(xyz[2])

    if x + y == z or x + z == y or y + z == x:
        print("YES")
    else:
        print("NO")