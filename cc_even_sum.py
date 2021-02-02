t = int(input())

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]

    ne = 0
    no = 0
    for a in a_vec:
        if a % 2 == 0:
            ne += 1
        else:
            no += 1
    
    if no % 2 == 0:
        print("1")
    else:
        print("2")