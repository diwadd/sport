

N = int(input())

a_vec = input().split(" ")
a_vec = [int(a) for a in a_vec]


if (N == 1):
    print(f"1 1\n0\n1 1\n0\n1 1\n{-a_vec[0]}")
else:
    
    print(f"1 {N}")

    s_vec = ["" for _ in range(N)]
    for n in range(0, N-1):
            s_vec[n] = str(-a_vec[n]*N)
    s_vec[N-1] = "0"
    print(" ".join(s_vec))

    print(f"1 {N-1}")
    s_vec = ["" for _ in range(N-1)]
    for n in range(0, N-1):
            s_vec[n] = str(a_vec[n]*(N-1))

    print(" ".join(s_vec))

    print(f"{N} {N}\n{-a_vec[N-1]}")