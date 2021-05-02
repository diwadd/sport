import math

t = int(input())

for _ in range(t):
    n = int(input())

    if n % 2 == 0:
        s = math.floor(math.sqrt(n // 2))
        if s * s == n // 2:
            print("YES")
            continue
    
    if n % 4 == 0:
        s = math.floor(math.sqrt(n // 4))
        if s * s == n // 4:
            print("YES")
            continue
    
    print("NO")