t = int(input())

for _ in range(t):

    n = int(input())

    s = input()
    p = input()

    d = 0
    for i in range(n):
        if p[i] == "1":
            d += 1

    are_different = False
    for i in range(n):
        if p[i] != s[i]:
            are_different = True
            break

    is_unique = False
    if d == n or d == 0:
        is_unique = True
    
    if is_unique == True and are_different == True:
        print("NO")
    else:
        print("YES")