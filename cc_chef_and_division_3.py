import math

t = int(input())

for _ in range(t):
    nkd = input().split(" ")
    nkd = [int(e) for e in nkd]

    n = nkd[0]
    k = nkd[1]
    d = nkd[2]

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]
    n_problems = sum(a_vec)

    d3_contests_overall = n_problems // k

    max_d3_contests = min(d3_contests_overall, d)

    print(max_d3_contests)