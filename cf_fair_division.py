import math

t = int(input())


for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")

    a_vec = [int(a) for a in a_vec]

    s = sum(a_vec)

    if s % 2 != 0:
        print("NO")
        continue

    d = {}
    for i in range(len(a_vec)):
        if a_vec[i] in d:
            d[a_vec[i]] += 1
        else:
            d[a_vec[i]] = 1

    m = s // 2
    
    n1s = None
    if 1 in d:
        n1s = d[1] 

    if (m % 2 != 0) and (n1s is None):
        print("NO")
    else:
        print("YES")
