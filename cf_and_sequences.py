import math

t = int(input())

for _ in range(t):

    n = int(input())

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    m = min(a_vec)

    c = 0
    is_ok = True
    for i in range(n):
        if a_vec[i] == m:
            c += 1

        if ((a_vec[i] & m) != m):
            is_ok = False
            break
    
    if is_ok == False:
        print(0)
    else:
        print((c*(c-1)*math.factorial(n-2))%(10**9+7))