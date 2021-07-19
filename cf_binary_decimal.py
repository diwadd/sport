import math

t = int(input())

for _ in range(t):

    n = int(input())

    st = str(n)
    st = [int(s) for s in st]

    print(max(st))
    