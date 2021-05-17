t = int(input())


MOD_7 = (10**9) + 7
MAX_N = 500000
POWERS_OF_2 = [1 for i in range(0, MAX_N)]

for i in range(1, len(POWERS_OF_2)):

    POWERS_OF_2[i] = ((POWERS_OF_2[i-1] % MOD_7) * 2 ) % MOD_7

# print(POWERS_OF_2)

for _ in range(t):

    n = int(input())

    print(POWERS_OF_2[n-1])

    # res = 0
    # for i in range(0, (2**n)):

    #     if i ^ (i + 1) == (i + 2) ^ (i + 3):
    #         print(i, end=" ")
    #         res += 1
    # print()
    # print(f"r--> {res}")