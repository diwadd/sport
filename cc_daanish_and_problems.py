t = int(input())

for _ in range(t):
    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    k = int(input())
    n = len(a_vec)

    for i in range(n-1, -1, -1):
        
        delta = min(a_vec[i], k)
        a_vec[i] -= delta
        k -= delta

        if k > 0:
            continue
        else:
            break
    
    index = 0
    for i in range(n-1, -1, -1):
        if a_vec[i] > 0:
            index = i + 1
            break

    print(index)