t = int(input())

for _ in range(t):

    L = int(input())
    a_vec = input()

    a_vec_int = [0 for _ in range(L)]
    for i in range(L):
        if a_vec[i] == "1":
            a_vec_int[i] = 1

    zeros = 0
    ones = 0
    is_yes = False
    for i in range(L):

        if a_vec_int[i] == 1:
            ones += 1
        
        if ones / (i+1) >= 0.5:
            print("YES")
            is_yes = True
            break
    
    if is_yes == False:
        print("NO")