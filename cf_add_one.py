t = int(input())

MAX_M = (2 * (10**5)) + 7 
dp = [2 for _ in range(MAX_M)]

dp[9] = 3

for i in range(10, MAX_M):
    dp[i] = dp[i-9] + dp[i-10]


print(f"dp size: {len(dp)}")

for _ in range(t):

    nm = input().split(" ")
    n = nm[0]
    m = int(nm[1])

    res = 0
    for d in n:

        if m + int(d) < 10:
            res += 1
        else:
            res += dp[m + int(d) - 10]

    print(res)
