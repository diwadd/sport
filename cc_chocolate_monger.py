t = int(input())


for _ in range(t):

    nx = input().split(" ")
    n = int(nx[0])
    x = int(nx[1])

    a_vec = input().split(" ")
    new_a_vec = []

    for a in a_vec:
        try:
            na = int(a)
            new_a_vec.append(na)
        except:
            pass
    
    # a_vec = [int(a) for a in a_vec]

    choco = {}
    for a in new_a_vec:
        if a in choco:
            choco[a] += 1
        else:
            choco[a] = 1

    for_bro = 0

    for c in choco:
        if choco[c] > 1:
            if x < choco[c]-1:
                for_bro += x
                choco[c] -= x 
            else:
                for_bro += choco[c] - 1
                choco[c] = 1
        if for_bro >= x:
            break
    
    if for_bro >= x:
        for_sab = 0
        for c in choco:
            if choco[c] > 0:
                for_sab += 1
        print(for_sab)
    else:
        for c in choco:
            if choco[c] > 0:
                for_bro += choco[c]
                choco[c] = 0
            if for_bro >= x:
                break

        for_sab = 0
        for c in choco:
            if choco[c] > 0:
                for_sab += 1
        print(for_sab)
