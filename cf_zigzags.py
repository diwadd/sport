import math


t = int(input())

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    freq = [[0 for _ in range(n+1)] for _ in range(n+1)]
    res = 0
    for j in range(n - 1, -1, -1):
        k = j + 1
        # print(f"freq: {freq}")
        for l in range(k+1, n):
            freq[a_vec[k]][a_vec[l]] += 1

        for i in range(0, j):
            res += freq[a_vec[i]][a_vec[j]]

    print(res)

