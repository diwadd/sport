t = int(input())

for _ in range(t):
    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    h_vec = input().split(" ")
    h_vec = [int(h) for h in h_vec]


    boulders = None
    k_index = 0
    for b in range(k):
        stopped = False
        for j in range(n-1):
            if h_vec[j] >= h_vec[j+1]:
                continue
            else:
                h_vec[j] += 1
                boulders = j
                # print(f"b: {b} j: {j}")
                stopped = True
                break
        
        if stopped == False:
            boulders = -1
            break;

    if boulders == -1:
        print(boulders)
    else:
        print(boulders+1)

    