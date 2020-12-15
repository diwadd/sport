import math

t = int(input())

for _ in range(t):

    nd = input().split(" ")
    n = int(nd[0])
    d = int(nd[1])

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    n_risk = 0
    n_non_risk = 0
    for i in range(len(a_vec)):

        if a_vec[i] >= 80 or a_vec[i] <= 9:
            n_risk +=1
        else:
            n_non_risk += 1

    res = int(math.ceil(n_risk / d)) + int(math.ceil(n_non_risk / d))
    print(res)