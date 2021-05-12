t = int(input())

for _ in range(t):
    nmk = input().split(" ")
    n = int(nmk[0])
    m = int(nmk[1])
    k = int(nmk[2])

    s2 = max(m,n) - 1 + (min(n,m) - 1) * max(m,n)

    # print(f"s2: {s2}")
    if s2 == k:
        print("YES")
    else:
        print("NO")