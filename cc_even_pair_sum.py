import math


def print_matrix(mat):

    n = len(mat)
    for a in range(1, n):
        for b in range(1, n):
            if b != n-1:
                print(f"{str(mat[a][b]).rjust(3)}", end=" ")
            else:
                print(f"{str(mat[a][b]).rjust(3)}", end="\n")


def get_number_of_even_sums_slow(a, b):

    s = 0
    for i in range(1, a+1):
        for j in range(1,b+1):

            if (i+j) % 2 == 0:
                s += 1
    return s

def get_number_of_even_sums_fast(a, b):

    def first_row(x): 
        return int(math.ceil(x/2.0))

    f = first_row(a)
    d = first_row(a-1)

    if a % 2 == 0:
        return int(f*b)
    else:
        x = None
        if b % 2 != 0:
            x = int((b-1) / 2)
            return f + x*d + x*(d+1)
        else:
            x = int(math.floor((b - 1) / 2) + 1)
            return f + x*d + (x-1)*(d+1)


t = int(input())

for _ in range(t):
    ab = input().split(" ")
    a = int(ab[0])
    b = int(ab[1])

    rf = get_number_of_even_sums_fast(a, b)
    print(rf)