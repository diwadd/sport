t = int(input())

for _ in range(t):

    nk = input().split()
    n = int(nk[0])
    k = int(nk[1])

    zebra = input()

    start = zebra[0]
    stop = zebra[-1]
    prev = zebra[0]

    n_cons = 0
    for z in zebra:

        if z == prev:
            # print(f"z: {z} - omit")
            continue
        else:
            # print(f"z: {z} - inc")
            prev = z
            n_cons += 1

    # print(f"n_cons: {n_cons}")

    index_sub_max = -1
    for i in range(n-1, -1, -1):
        if zebra[i] != prev:
            index_sub_max = i
            break

    # print(f"index_sub_max: {index_sub_max}")

    if n_cons == 0 or k > n_cons:
        print(-1)
    else:
        if start != stop:
            if k % 2 == 0:
                print(index_sub_max+1)
            else:
                print(n)
        else:
            if k % 2 == 0:
                print(n)
            else:
                print(index_sub_max+1)

