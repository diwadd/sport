import math

t = int(input())

for _ in range(t):

    N = int(input())

    print(f"{N}")
    for n in range(1, N+1):
        if(n != N):
            print(f"{n}", end=" ") 
        else:
            print(f"{n}", end="\n")