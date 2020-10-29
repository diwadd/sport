import math
 
t = int(input())
 
for _ in range(t):
 
    abc = input().split(" ")
    a = int(abc[0])
    b = int(abc[1])
    c = int(abc[2])
 
    v = [a, b, c]
    v.sort()
 
    d = v[1] + v[2]
 
    print(d)