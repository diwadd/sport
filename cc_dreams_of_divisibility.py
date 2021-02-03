import math

t = int(input())

for _ in range(t):

    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    while k % 2 == 0:

        k = k // 2


    if k == 1:
        print("YES")
        continue

    # print(f"k: {k}")

    is_ok = True
    for i in range(len(a_vec)):
        if a_vec[i] % k != 0:
            is_ok = False
    
    if is_ok:
        print("YES")
    else:
        print("NO")