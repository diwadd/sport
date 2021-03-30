t = int(input())

for _ in range(t):

    MAX_SQUARE = 1000
    for i in range(1, MAX_SQUARE + 1):
        print(i*i)

        res = int(input())

        if res == 1:
            break
        else:
            continue