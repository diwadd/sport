import copy
import sys

MAX_REC = 1000000000
sys.setrecursionlimit(MAX_REC)

def knapsack(n, capacity, weights, cost, dp):
    # print(f"n: {n} capacity: {capacity}")
    if n == -1 or capacity == 0:
        return 0
    elif dp[n][capacity] is not None:
        # print(f"Returning from dp...")
        return dp[n][capacity]
    elif weights[n] > capacity:
        return knapsack(n-1, capacity, weights, cost, dp)
    else:
        t1 = knapsack(n-1, capacity, weights, cost, dp)
        t2 = cost[n] + knapsack(n-1, capacity - weights[n], weights, cost, dp)
        dp[n][capacity] = max(t1, t2)
        return dp[n][capacity]

n = int(input())
w_vec = [0 for _ in range(n)]
c_vec = [0 for _ in range(n)]

for i in range(n):
    wc = input().split(" ")
    w = int(wc[0])
    c = int(wc[1])

    w_vec[i] = w
    c_vec[i] = c

    m = sum(w_vec)

r_vec = [0 for _ in range(m)]
dp = [[None for _ in range(m+1)] for _ in range(n)]
for j in range(1, m+1):
    start = copy.deepcopy(n)
    r = knapsack(start-1, j, w_vec, c_vec, dp)
    r_vec[j-1] = str(r)
    # print(f"j: {j} r: {r}")

res = " ".join(r_vec)
print(res)