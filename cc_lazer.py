from collections import namedtuple

MAX_N = 100000 + 7

class FenwickTree:
    def __init__(self, n):
        self.t = [0 for _ in range(n+1)]
        self.local_n = None

    def sum(self, index):
        res = 0
        # print("Summing...")
        while index > 0:
            # print(f"index: {index}")
            res += self.t[index]
            index -= (index & (-index))
        return res

    def update(self, index, value):
        # print(f"Updating tree... for index: {index} and value {value}")
        while index < self.local_n:
            # print(f"index: {index}")
            self.t[index] += value
            index += (index & (-index))

t = int(input())


q_vec = [[0, 0, 0] for _ in range(MAX_N)]
res = [0 for _ in range(MAX_N)]
ft = FenwickTree(MAX_N)

for _ in range(t):
    nq = input().split(" ")
    n = int(nq[0])
    q = int(nq[1])

    ft.local_n = n + 1
    a_vec = [int(a) for a in input().split(" ")]

    for i in range(q):
        x1x2y = input().split(" ")

        q_vec[i][0] = int(x1x2y[0])
        q_vec[i][1] = int(x1x2y[1])
        q_vec[i][2] = int(x1x2y[2])

    events = []
    # Evt = namedtuple("Evt", ["y", "t", "i"])
    for i in range(n-1):
        e_low = (min(a_vec[i], a_vec[i+1]), 1, i)
        e_high = (max(a_vec[i], a_vec[i+1]), 3, i)  
        
        events.append(e_low)
        events.append(e_high)
    
    for i in range(q):
        e_lazer = (q_vec[i][2], 2, i)
        events.append(e_lazer)

    events.sort(key=lambda x: (x[0], x[1]))
    # print(events)

    for e in events:
        # print(f"e: {e}")
        if e[1] == 1:
            ft.update(e[2]+1, 1)
            # print(ft.t)
        elif e[1] == 2:
            # print(f"q_vec[e[2]][1]: {q_vec[e[2]-1][1]} q_vec[e[2]][0]: {q_vec[e[2]-1][0]}")
            res[e[2]] = ft.sum(q_vec[e[2]][1]-1) - ft.sum(q_vec[e[2]][0]-1)
        elif e[1] == 3:
            ft.update(e[2]+1, -1)
            # print(ft.t)

    for i in range(q):
        print(res[i])


