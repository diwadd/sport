import math

t = int(input())

for _ in range(t):
    nk = input().split(" ")

    n = int(nk[0])
    k = int(nk[1])

    a_vec = []

    for i in range(k+1, n+1):
        # print(f"i: {i}")
        a_vec.append(str(i))

    left = 1
    right = k - 1

    while left <= right:
        a_vec.append(str(right))
        right -= 1
        left += 1

    print(len(a_vec))
    res = " ".join(a_vec)
    print(res)