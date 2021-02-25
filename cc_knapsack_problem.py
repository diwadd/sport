import copy
import sys

MAX_REC = 1000000000
sys.setrecursionlimit(MAX_REC)

n = int(input())
w_vec = [0 for _ in range(n)]
c_vec = [0 for _ in range(n)]

n_ones = 0
n_twos = 0

for i in range(n):
    wc = input().split(" ")
    w = int(wc[0])
    c = int(wc[1])

    w_vec[i] = w
    c_vec[i] = c

    if w == 1:
        n_ones += 1
    elif w == 2:
        n_twos += 1

m_max = sum(w_vec)

c_ones = [0 for _ in range(n_ones)]
c_twos = [0 for _ in range(n_twos)]


o_index = 0
t_index = 0
for i in range(n):
    if w_vec[i] == 1:
        c_ones[o_index] = c_vec[i]
        o_index += 1
    elif w_vec[i] == 2:
        c_twos[t_index] = c_vec[i]
        t_index += 1


c_ones.sort()
c_twos.sort()

c_ones_2 = copy.deepcopy(c_ones)
c_twos_2 = copy.deepcopy(c_twos)

res = [0 for _ in range(0, m_max + 1)]

if len(c_ones_2) > 0:
    res[1] = c_ones_2.pop()

even_sum = 0
for m in range(2, m_max + 1, 2):

    t1 = sum(c_ones[-2:])
    t2 = sum(c_twos[-1:])

    if t1 > t2:
        even_sum += t1
        res[m] = even_sum
        if len(c_ones) > 0:
            c_ones.pop()
        if len(c_ones) > 0:
            c_ones.pop()
    else:
        even_sum += t2
        res[m] = even_sum
        if len(c_twos) > 0:
            c_twos.pop()

even_sum = res[1]
for m in range(3, m_max + 1, 2):
    t1 = sum(c_ones_2[-2:])
    t2 = sum(c_twos_2[-1:])

    if t1 > t2:
        even_sum += t1
        res[m] = even_sum
        if len(c_ones_2) > 0:
            c_ones_2.pop()
        if len(c_ones_2) > 0:
            c_ones_2.pop()
    else:
        even_sum += t2
        res[m] = even_sum
        if len(c_twos_2) > 0:
            c_twos_2.pop()


# print(res)

res = [str(r) for r in res]

res = " ".join(res[1:])
print(res)