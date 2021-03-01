bt = int(input())

for _ in range(bt):
    word = input()

    MAX_LETTERS = 25
    A_NUM = 97
    letters = [0 for _ in range(MAX_LETTERS+1)]

    for w in word: 
        letters[ord(w) - A_NUM] += 1

    n_twos = 0
    n_ones = 0
    for l in letters:
        t = l // 2
        o = l % 2

        n_twos += t
        n_ones += o

    if n_ones <= n_twos:
        print("YES")
    else:
        print("NO")

