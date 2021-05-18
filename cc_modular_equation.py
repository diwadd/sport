import math

def count_pairs_bf(n, m):
    
    res = 0
    mat = [[0 for _ in range(n)] for _ in range(n)]
    for a in range(1, n+1):
        for b in range(1, n+1):
            if a < b:
                if ((m % a) % b) == ((m % b) % a):
                    res += 1
                    mat[a-1][b-1] = 1
                    # print(f"({a},{b})", end=" ")
    # print()

    return res

def divisors(n):

    sn = math.floor(math.sqrt(n))
    d1 = []
    d2 = []
    for i in range(1, sn + 1):
        if n % i == 0:
            if n // i == i:
                d1.append(i)
            else:
                d1.append(i)
                d2.append(n // i)

    return d1 + d2[::-1]

def count_pairs_fast(n, m):

    res = 0
    for b in range(2, n+1):
        y = m - m % b

        if b <= m:

            d = divisors(y)
            index = 0
            for i in range(len(d)):
                if d[i] >= b:
                    index = i
                    break
                
            res += index
        else:
            res += (b-1)

    return res

t = int(input())

for _ in range(t):

    nm = input().split(" ")
    n = int(nm[0])
    m = int(nm[1])

    # print(divisors(n))

    # p1 = count_pairs_bf(n, m)
    p2 = count_pairs_fast(n, m)

    # print(f"{p1} {p2}")
    print(p2)