t = int(input())
    
    
n2050 = [2050*(10**k) for k in range(16, -1, -1)]
    
for _ in range(t):
    
    n = int(input())
    
    res = 0
    for i in range(len(n2050)):
    
        n2 = n2050[i]
    
        if n // n2 == 0:
            continue
        else:
            res += n // n2
            n = n - (n // n2)*n2
    
    if res == 0 or n != 0:
        print(-1)
    else:
        print(res)