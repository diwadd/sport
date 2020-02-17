import math
import heapq
import itertools

if __name__ == "__main__":

    dim = 4
    p = list(itertools.permutations([0, 1, 2, 3], 4))
    # print(p)

    mapping_acbd = {"A": 0, "B": 1, "C": 2, "D": 3}
    mapping_36912 = {"3": 0, "6": 1, "9": 2, "12": 3}

    t = int(input())

    total = 0
    for i in range(t):

        n = int(input())

        abcd_matrix = [[0 for j in range(dim)] for k in range(dim)]
        for j in range(n):
            line = input().split(" ")
            m = line[0]
            h = line[1]

            y = mapping_acbd[m]
            x = mapping_36912[h]

            abcd_matrix[y][x] += 1 

        # for j in range(dim):
        #     for k in range(dim):
        #         print(abcd_matrix[j][k],end=" ")
        #     print()

        # This is a brute force solution of finding the maximum.
        # We directly iterate over the 4! = 24 permutations.
        # No sure if there is a different method?
        e = -math.inf
        prices = [100, 75, 50, 25]
        for j in range(len(p)):
            vs = [0, 0, 0, 0]
            for k in range(len(p[j])):
                # print(f"j: {j} k: {k} p[{j}][{k}]: {p[j][k]}")
                vs[k] = abcd_matrix[k][p[j][k]]
            vs.sort(reverse=True)
            # print(vs)

            temporary_price = 0
            for k in range(dim):
                if vs[k] != 0:
                    temporary_price += vs[k]*prices[k]
                else:
                    temporary_price -= 100

            # print(f"temporary_price: {temporary_price}")
            if temporary_price > e:
                e = temporary_price


        total += e
        print(e)
    print(total)