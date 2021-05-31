t = int(input())

for _ in range(t):

    abcdk = input().split(" ")
    a = int(abcdk[0])
    b = int(abcdk[1])
    c = int(abcdk[2])
    d = int(abcdk[3])
    k = int(abcdk[4])

    d = abs(a - c) + abs(b - d)
    # print(f"->{d} {k}")
    if d > k:
        print("NO")
    elif d == k:
        print("YES")
    elif d < k:
        delta = d - k
        # print(f"-->{delta}")
        if delta % 2 == 0:
            print("YES")
        else:
            print("NO")