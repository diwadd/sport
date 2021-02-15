from datetime import datetime

t = int(input())

for _ in range(t):
    p = input()

    format = '%I:%M %p'
    p = datetime.strptime(p, format).time()

    n = int(input())
    res = [None for _ in range(n)]

    for i in range(n):
        lr = input()
        l = lr[0:8]
        r = lr[9:]

        l = datetime.strptime(l, format).time()        
        r = datetime.strptime(r, format).time()

        if (l <= p and p <= r):
            res[i] = "1"
        else:
            res[i] = "0"

    print("".join(res))