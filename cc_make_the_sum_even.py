t = int(input())

for _ in range(t):

    n = int(input())
    a_vec = input().split(" ")

    a_vec = [int(a) for a in a_vec]


    s = 0
    is_two = False
    for a in a_vec:
        s += a
        if a == 2:
            is_two = True

    if s % 2 == 0:
        print(0)
    else:
        if is_two == True:
            print(1)
        else:
            print(-1)