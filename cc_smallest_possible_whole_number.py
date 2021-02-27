t = int(input())


for _ in range(t):
        nk = input().split(" ")
        n = int(nk[0])
        k = int(nk[1])

        if k == 0:
            print(n)
        else:
            a = n // k
            print(n - a*k)