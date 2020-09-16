import math

t = int(input())

def print_dp(i, dp):

    lj = 3
    print(f"dp[{i}][0]: ", end=" ")
    for j in range(len(dp)):
        print(str(dp[j][0]).ljust(lj), end=" ")

    print(f"dp[{i}][1]: ", end=" ")
    for j in range(len(dp)):
        print(str(dp[j][1]).ljust(lj), end=" ")
    print()

for _ in range(t):
    n = int(input())
    a_vec = input().split(" ")
    # print(f"a_vec: {a_vec}")
    a_vec = [int(a) for a in a_vec]

    dp = [[math.inf, math.inf] for i in range(n+1)]
    # print(f"len(dp): {len(dp)}")
    dp[0][1] = 0
    for i in range(n):
        print_dp(i, dp)
        for w in range(2):
            for f in range(1, min(n-i, 2) + 1):

                d = 0
                if f > 1:
                    d = a_vec[i+1]
                h = a_vec[i] + d
                index = 0
                if w == 0:
                    index = 1
                # print(f"i+f: {i+f} index: {index}")
                dp[i+f][index] = min(dp[i+f][index], dp[i][w] + w * h)
    print(min(dp[n][0],dp[n][1]))
