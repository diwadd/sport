t = int(input())


for _ in range(t):

    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    perm = [i for i in range(1, n+1)]

    switches = 0
    for j in range(1, k+1):
        index = 2*j-1
        if(index + 1 < len(perm)):
            perm[index], perm[index+1] = perm[index+1], perm[index]
            switches += 1
        
        if switches >= k:
            break
    
    if switches < k:
        print(-1)
    else:
        perm = [str(p) for p in perm]
        print(" ".join(perm))
