from itertools import permutations
from itertools import combinations
import math


def tuple_xor(t1, t2):

    n = len(t1)
    r = [0 for i in range(n)]
    for i in range(n):
        if (t1[i] == 1 and t2[i] == 0) or (t1[i] == 0 and t2[i] == 1):
            r[i] = 1
    return tuple(r)

def number_of_xors(p):

    n = len(p)
    for i in range(n):
        perms1 = list(set(permutations(p[i])))
        for j in range(n):
            print(f"{p[i]} -> {p[j]}", end="")
            perms2 = list(set(permutations(p[j])))
            n_xors = set()
            for a in range(len(perms1)):
                t1 = perms1[a]
                for k in range(len(perms2)):
                    t2 = perms2[k]
                    xor = tuple_xor(t1, t2)
                    n_xors.add(xor)

            print(f" XORs: {len(n_xors)}", end="")

            unique_xor_perm = set()
            for x in n_xors:
                unique_xor_perm.add(tuple(sorted(x)))
            print(f" perms: {len(unique_xor_perm)}")

if __name__ == "__main__":
    print("Binary XOR support")

    n = 21
    o = [1 for i in range(n)]
    z = [0 for i in range(n)]

    for m in range(1, 10):
        print(f"Number of XORs for m = {m}")
        p = None
        # m = 6
        if m < n/2:
            p = list(set(combinations(o + z, m)))
        # print(set(list(p)))
        number_of_xors(p)