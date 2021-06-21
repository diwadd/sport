import math

t = int(input())

for _ in range(t):

    n = int(input())

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    o = []
    e = []
    for a in a_vec:
        if a % 2 == 0:
            e.append(a)
        else:
            o.append(a)

    s_vec = e + o

    res = 0
    for i in range(n):
        for j in range(i+1, n):
            if math.gcd(s_vec[i], 2*s_vec[j]) > 1:
                res += 1

    print(res)