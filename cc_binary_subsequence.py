import math

t = int(input())

for _ in range(t):

    n = int(input())
    bs = input()
    bs = [int(s) for s in bs]

    psum = [0 for _ in range(len(bs))]
    ssum = [0 for _ in range(len(bs))]

    psum[0] = bs[0]
    
    if bs[-1] == 0:
        ssum[-1] = 1

    for i in range(1, len(bs)):
        if bs[i] == 1:
            psum[i] = psum[i-1] + 1
        else:
            psum[i] = psum[i-1]

    for i in range(len(bs)-2, -1, -1):
        if bs[i] == 0:
            ssum[i] = ssum[i+1] + 1
        else:
            ssum[i] = ssum[i+1]

    res = math.inf
    for i in range(len(bs)):
        
        r0 = 0
        r1 = 0
        if bs[i] == 1:
            r0 = ssum[i]
            r1 = psum[i] - 1
        else:
            r0 = ssum[i] - 1
            r1 = psum[i]

        res = min(res, r0 + r1)

    print(res)
