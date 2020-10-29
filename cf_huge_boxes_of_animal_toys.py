import math

t = int(input())

for _ in range(t):
    abcd = input().split()

    a = int(abcd[0])
    b = int(abcd[1])
    c = int(abcd[2])
    d = int(abcd[3])

    if a == 0 and d == 0:
        if b % 2 == 0:
            print("Tidak Tidak Ya Tidak")
        else:
            print("Tidak Ya Tidak Tidak")
    elif b == 0 and c == 0:
        if a % 2 == 0:
            print("Tidak Tidak Tidak Ya")
        else:
            print("Ya Tidak Tidak Tidak")
    else:
        if (a+b) % 2 == 0:
            print("Tidak Tidak Ya Ya")
        else:
            print("Ya Ya Tidak Tidak")