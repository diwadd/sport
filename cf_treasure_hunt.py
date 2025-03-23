t = int(input())


for _ in range(t):
    x, y, a = [int(s) for s in input().split(" ")]

    if (x > a):
        print("NO")
        continue

    b = x+y
    d = a // (x+y)

    if ( (d*b) == a):
        print("NO")
        continue
    
    if ((d*b + x) > a):
        print("NO")
        continue

    if ((d*b + x) <= a):
        print("YES")
        continue
