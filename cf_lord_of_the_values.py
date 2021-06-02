t = int(input())
    
def ao(a, i, j):
    a[i] = a[i] + a[j]
ao.t = 1
    
def at(a, i, j):
    a[j] = a[j] - a[i]
at.t = 2
    
def reverse_values(a):
    
    seq = [ao, at, ao, at, ao, at]
    for i in range(0, len(a), 2):
        for s in seq:
            s(a, i, i+1)
            print(f"{s.t} {i+1} {i+2}")
    
for _ in range(t):
    
    n = int(input())
    
    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]
    
    print(f"{3*n}")
    reverse_values(a_vec)