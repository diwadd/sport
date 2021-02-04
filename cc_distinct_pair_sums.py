import math

t = int(input())

for _ in range(t):

    lr = input().split(" ")
    l = int(lr[0])
    r = int(lr[1])

    print(2*r - 2*l + 1)