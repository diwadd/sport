t = int(input())

for _ in range(t):
    qd = input().split(" ")
    q = int(qd[0])
    d = int(qd[1])

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    MAX_DIGIT = 100
    dp = [0 for _ in range(MAX_DIGIT)]
    dp[0] = 1
    dp[d] = 1

    for i in range(1, MAX_DIGIT):
        for j in range(0, 10):
            if i >= j*10+d:
                dp[i] = dp[i] | dp[i-(j*10+d)]

    for a in a_vec:
        if a > 10*d:
            print("YES")
        else:
            if dp[a] == 1:
                print("YES")
            else:
                print("NO")






