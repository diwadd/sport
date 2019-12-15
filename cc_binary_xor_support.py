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
        t1 = p[i]
        
        for j in range(n):
            print(f"{t1} -> {p[j]}", end="")
            perms = list(set(permutations(p[j])))
            n_xors = set()
            for k in range(len(perms)):
                t2 = perms[k]
                xor = tuple_xor(t1, t2)
                n_xors.add(xor)
            print(f" XORs: {len(n_xors)}")


if __name__ == "__main__":
    print("Binary XOR support")

    n = 20
    o = [1 for i in range(n)]
    z = [0 for i in range(n)]

    p = None
    m = 6
    if m < n/2:
        p = list(set(combinations(o + z, m)))
    # print(set(list(p)))
    number_of_xors(p)