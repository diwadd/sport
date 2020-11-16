import math

t = int(input())

for _ in range(t):
    n = int(input())
    c_vec = input().split(" ")

    if n == 1:
        print(f"{c_vec[0]}")
        continue

    c_set = [int(c) for c in c_vec]
    c_set.sort()

    lb = c_set[-1]
    del c_set[-1]

    rb = c_set[-1]
    del c_set[-1]

    res = 0
    while True:

        lb = max(0, lb - 1)
        rb = max(0, rb - 1)
        res += 1

        if lb == 0 and rb == 0 and len(c_set) == 0:
            break

        if len(c_set) != 0:
            if lb == 0:
                lb = c_set.pop()
        if len(c_set) != 0:
            if rb == 0:
                rb = c_set.pop()
    print(f"{res}")
