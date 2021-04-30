t = int(input())

for _ in range(t):

    rbd = input().split(" ")
    r = int(rbd[0])
    b = int(rbd[1])
    d = int(rbd[2])

    if r > b:
        r, b = b, r

    # print(f"{r} {b} {d} {r*(d+1)}")

    if b <= r*(d+1):
        print("YES")
    else:
        print("NO")