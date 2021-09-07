def xor_up_to_n(n):

    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return 1
    elif n % 4 == 2:
        return n + 1
    elif n % 4 == 3:
        return 0

t = int(input())

for _ in range(t):
    ab = input().split(" ")
    a = int(ab[0])
    b = int(ab[1])

    s = xor_up_to_n(a - 1)
    # print(f"--> {s}")

    if s == b:
        print(a)
    else:
        if s ^ a == b:
            print(a + 2)
        else:
            print(a + 1)