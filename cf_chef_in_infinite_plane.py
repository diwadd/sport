t = int(input())

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    d = {}
    for a in a_vec:
        if a in d:
            d[a] += 1
        else:
            d[a] = 1

    res = 0

    for k, v in d.items():
        res += min(v, k-1)

    print(res)