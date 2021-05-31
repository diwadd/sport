t = int(input())

def get_distance(q1, q2):

    if (q1 == 1 and q2 == 1) or (q1 == 0 and q2 == 0):
        return 2
    elif (q1 == 0 and q2 == 1) or (q1 == 1 and q2 == 0):
        return 1

def change_charge(charges, p):
    if charges[p] == 1:
        charges[p] = 0
    else:
        charges[p] = 1

for _ in range(t):
    nk = input().split(" ")
    n = int(nk[0])
    k = int(nk[1])

    charges = input()
    charges = [int(c) for c in charges]
    
    q_vec = input().split(" ")
    q_vec = [int(q)-1 for q in q_vec]

    if n > 1:

        d = 0
        for i in range(1, len(charges)):
            d += get_distance(charges[i-1], charges[i])

        for i in range(len(q_vec)):
            q = q_vec[i]
            old_delta = 0
            new_delta = 0
            if q != 0 and q != n-1:
                old_delta = get_distance(charges[q-1], charges[q]) + get_distance(charges[q], charges[q+1])
                change_charge(charges, q)
                new_delta = get_distance(charges[q-1], charges[q]) + get_distance(charges[q], charges[q+1])
            elif q == 0:
                old_delta = get_distance(charges[q], charges[q+1])
                change_charge(charges, q)
                new_delta = get_distance(charges[q], charges[q+1])
            elif q == n - 1:
                old_delta = get_distance(charges[q-1], charges[q])
                change_charge(charges, q)
                new_delta = get_distance(charges[q-1], charges[q])
            
            d = d - old_delta + new_delta
            print(d)
    elif n == 1:
        for i in range(len(q_vec)):
            print(0)