import math

t = int(input())

for _ in range(t):

    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    family_members = input().split(" ")
    family_members = [int(f) for f in family_members]
    # print(f"n: {n} k: {k}")
    # print(family_members)

    dp = [math.inf for _ in range(n+1)]
    dp[0] = 0

    MAX_MEMBER = 101
    for i in range(n):
        # print(dp)
        freq = [0 for _ in range(MAX_MEMBER)]
        for j in range(i, n):
            freq[family_members[j]] += 1
            arguing_guests = 0
            for m in range(1, 101):
                if freq[m] > 1:
                    arguing_guests += freq[m]
            # print(f"j: {j} arguing_guests: {arguing_guests} dp[{i}]: {dp[i]} dp[{j+1}]: {dp[j+1]} dp[{i}] + ag + m: {dp[i] + arguing_guests + m}")
            dp[j+1] = min(dp[j+1], dp[i] + arguing_guests + k)

    print(dp[n])