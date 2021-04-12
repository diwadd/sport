t = int(input())

for _ in range(t):

    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    strong = input()
    f = False

    found_stars = 0
    for s in strong:
        if s != "*":
            found_stars = 0
        elif s == "*":
            found_stars += 1

        if found_stars == k:
            f = True
            break


    if f == False:
        print("NO")
    else:
        print("YES")