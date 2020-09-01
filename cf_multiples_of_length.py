

N = int(input())

a_vec = input().split(" ")
a_vec = [int(a) for a in a_vec]


if (N == 1):
    print(f"1 1\n0\n1 1\n0\n1 1\n{-a_vec[0]}")
else:
    
    print(f"1 {N}")
    s = ""

    for n in range(0, N-1):
            s = s + str(-a_vec[n]*N) + " "
    s = s + "0"
    print(s)

    print(f"1 {N-1}")
    s = ""
    for n in range(0, N-1):
        if(n != N-2):
            s = s + str(a_vec[n]*(N-1)) + " "
        else:
            s = s + str(a_vec[n]*(N-1))
    print(s)

    print(f"{N} {N}\n{-a_vec[N-1]}")