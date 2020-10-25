import math

def print_matrix(mat):
    print("---")
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            print(mat[i][j], end=" ")
        print()

if __name__ == "__main__":

    n_latin = 26
    m2 = [[0 for i in range(n_latin)] for j in range(n_latin)]
    m1 = [0 for i in range(n_latin)]

    message = input()
    n = len(message)

    for i in range(n):
        c = ord(message[i]) - ord('a')
        for j in range(n_latin):
            m2[j][c] += m1[j]
        m1[c] += 1
        # print_matrix(m2)
        # print(m1)
    

    r1 = max(m1)
    for i in range(n_latin):
        for j in range(n_latin):
            if m2[i][j] > r1:
                r1 = m2[i][j]
    print(r1)