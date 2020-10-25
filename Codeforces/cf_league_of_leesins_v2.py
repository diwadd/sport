import math
import random
 
 
def l_perm(n, q):

    seen = [False for i in range(n+1)]
    binding = [[] for i in range(n+1)]
    freq = [0 for i in range(n+1)]

    m = len(q)
    for i in range(m):
        x = q[i][0]
        y = q[i][1]
        z = q[i][2]
        binding[x].append(y)
        binding[x].append(z)

        binding[y].append(x)
        binding[y].append(z)  
        
        binding[z].append(x)
        binding[z].append(y) 

        freq[x] += 1
        freq[y] += 1
        freq[z] += 1

    f = None
    s = None

    for i in range(n+1):
        if freq[i] == 1:
            f = i
            break

    if freq[binding[f][0]] == 2:
        s = binding[f][0]
    else:
        s = binding[f][1]

    p = [str(f), str(s)]
    seen[f] = True
    seen[s] = True

    i = 2
    t = None
    while i < n:
        for e in binding[f]:
            if seen[e] == False:
                t = e
                break
        p.append(str(t))
        seen[t] = True 
        f = s
        s = t
        i += 1

    return " ".join(p)
    
    # p = [int(j) for j in p]
    # return p



def generate_test_case(n=10):
 
    p = [i for i in range(1,n+1)]
    random.shuffle(p)
 
    q = []
    for i in range(2, n):
        w = p[(i-2):(i+1)]
        random.shuffle(w)
        q.append(w)
 
    return p, q
 
if __name__ == "__main__":
    # for i in range(10):
    #     print(f"i = {i}")
    #     n = random.randint(5,100000)
    #     p, q = generate_test_case(n=n)
    #     ep = l_perm(n, q)
    #     if p[0] != ep[0]:
    #         ep.reverse()
    #     assert p == ep, f"Permutation not equal! \n{p}\n{ep}"
 
 
    n = int(input())
    q = [[0,0,0] for i in range(n-2)]
    for i in range(n-2):
        s = input().split(" ")
        s = [int(j) for j in s]
        q[i] = s
 
    ep = l_perm(n, q)
    print(ep)