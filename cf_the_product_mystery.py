import math

t = int(input())

for _ in range(t):

    bc = input().split(" ")
    b = int(bc[0])
    c = int(bc[1])

    lcm = (b*c) // math.gcd(b, c)
    res = lcm // b

    print(res)
