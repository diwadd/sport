import math

t = int(input())

for _ in range(t):
    x = int(input())

    d = math.sqrt(1+8*x)
    n = math.ceil((-1.0+d)/2.0)
    m = n*(n+1)/2

    if m == x:
        print(n)
    elif m - 1 == x:
        print(n+1)
    else:
        print(n)