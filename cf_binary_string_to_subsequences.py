import math


t = int(input())

for _ in range(t):

    n = int(input())
    s = input()

    res = [0 for _ in range(n)]
    zero = []
    one = []
    for i in range(n):
        p = len(zero) + len(one)
        if s[i] == "0":
            if(len(one) == 0):
                zero.append(p)
            else:
                p = one.pop()
                zero.append(p)
        else:
            if len(zero) == 0:
                one.append(p)
            else:
                p = zero.pop()
                one.append(p)
        res[i] = p


    print(len(zero) + len(one))
    # print(f"res: {res}")
    for j in range(n):
        if j != n-1:
            print(res[j] + 1, end=" ")
        else:
            print(res[j] + 1)