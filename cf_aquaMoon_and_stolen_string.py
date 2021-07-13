import sys

t = int(input())

def missing_letter(freq):
    for i in range(len(freq)):
        if freq[i] != 0:
            return i

for _ in range(t):

    nm = input().split(" ")
    n = int(nm[0])
    m = int(nm[1])

    N_LETTERS = 26 + 1
    letters = [[0 for _ in range(N_LETTERS)] for _ in range(m)]
    for _ in range(n):
        n_string = input()
        for i in range(len(n_string)):
            s = n_string[i]
            letters[i][ord(s) - ord('a')] += 1

    for _ in range(n-1):
        minus_string = input()
        for i in range(len(minus_string)):
            s = minus_string[i]
            letters[i][ord(s) - ord('a')] -= 1

    res = ""
    for i in range(m):
        c = missing_letter(letters[i])
        res += chr(c + ord('a'))

    print(res)
    sys.stdout.flush()
