t = int(input())

for _ in range(t):

    n = int(input())

    ep = input()
    gp = input()

    ep = [int(c) for c in ep]
    gp = [int(c) for c in gp]

    for i in range(n):
        if gp[i] == 0:
            continue
        else:
            if ep[i] == 0:
                ep[i] = 2
                continue

            left = None
            right = None
            if i-1 >= 0:
                left = i-1
            if i + 1 < n:
                right = i+1

            if left is not None:
                if ep[left] == 1:
                    ep[left] = 2
                    continue
            if right is not None:
                if ep[right] == 1:
                    ep[right] = 2
                    continue
    
    res = 0
    for i in range(n):
        if ep[i] == 2:
            res += 1
    
    print(res)