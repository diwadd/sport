import math

n = int(input())

for _ in range(n):

    s = input()
    r = s[::-1]

    res = 0
    i = 0
    for j in range(len(r)):

        if i == len(s):
            break

        while s[i] != r[j]:
            i += 1
            if i == len(s):
                break

        if i == len(s):
            break

        if s[i] == r[j]:
            res += 1
            i += 1

    print(f"{len(s) - res}")
