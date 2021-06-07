#!/usr/bin/env python3

tests = int(input())


for t in range(1, tests + 1):

    whlurd = input().split(" ")
    w, h, l, u, r, d = [int(dim) for dim in whlurd]

    grid = [[1 for _ in range(w+1)] for _ in range(h+1)]

    for i in range(1, w+1):
        for j in range(1, h+1):
            if (i >= l and i <= r) and ((j >= u and j <= d)):
                grid[j][i] = 0

    # for row in grid:
    #     print(row)

    p = 0.5
    prob = [[0 for _ in range(w+1)] for _ in range(h+1)]
    prob[1][1] = 1.0
    for i in range(1, w+1):
        for j in range(1, h+1):
            
            if i == 1 and j == 1:
                continue
            if grid[j-1][i] == 1:
                if i == w:
                    prob[j][i] = prob[j][i] + prob[j-1][i]
                else:
                    prob[j][i] = prob[j][i] + p*prob[j-1][i]

            if grid[j][i-1] == 1:
                if j == h:
                    prob[j][i] = prob[j][i] + prob[j][i-1]
                else:
                    prob[j][i] = prob[j][i] + p*prob[j][i-1]

    print(f"Case #{t}: {prob[h][w]}")

    # print("--- --- ---")
    # for row in prob:
    #     print(row)