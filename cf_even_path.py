import math
import heapq

def even_earth(n, r, c, sv, tv):

    board = [[0 for i in range(n+1)] for j in range(n+1)]
    graph = [[] for i in range((n+1)*(n+1))]


    for i in range(1, n+1):
        for j in range(1, n+1):
            bc = r[i] + c[j]
            if bc % 2 != 0:
                continue

            bn = None
            be = None
            bs = None
            bw = None
            index = n*(i-1) + j - 1
            if i - 1 >= 1:
                bn = r[i-1] + c[j]
                if bn % 2 == 0:
                    graph[index].append([i-1, j])

            if i + 1 <= n:
                bs = r[i+1] + c[j]
                if bs % 2 == 0:
                    graph[index].append([i+1, j])

            if j - 1 >= 1:
                bw = r[i] + c[j-1]
                if bw % 2 == 0:
                    graph[index].append([i, j-1])

            if j + 1 <= n:
                be = r[i] + c[j+1]
                if be % 2 == 0:
                    graph[index].append([i, j+1])

    for i in range(1, n+1):
        for j in range(1, n+1):
            s = f"i = {i} j = {j} nodes: "
            index = n*(i-1) + j - 1
            for k in range(len(graph[index])):
                s += f" {graph[index][k]} "

            print(s)



    for i in range(1, n+1):
        for j in range(1, n+1):
            board[i][j] = r[i] + c[j]

    for i in range(1, n+1):
        s = ""
        for j in range(1, n+1):
            s = s + str(board[i][j]).rjust(3)
        print(s)

    si = sv[0]
    sj = sv[1]
    ti = tv[0]
    tj = tv[1]

    s_index = n*(si-1) + sj - 1
    t_index = n*(ti-1) + tj - 1

    n_vertices = len(graph)
    d = [[math.inf, i] for i in range(n_vertices)]
    p = [None for i in range(n_vertices)]
    q = []
    d[s_index][0] = 0

    heapq.heapify(q)
    heapq.heappush(q, [0,s_index])

    # print(heapq.heappop(q))

    t_found = False
    while len(q) > 0:
        current_node = heapq.heappop(q)

        if current_node[1] == t_index:
            t_found = True
            break

        current_node_index = current_node[1]
        print(f"current node index: {current_node_index}")

        neighbour_nodes = graph[current_node_index]
        print(f"neighbour_nodes: {neighbour_nodes}")

        for neighbour in neighbour_nodes:
            print(f"d[current_node_index]: {d[current_node_index]}")
            new_d = d[current_node_index][0] + 1
            neighbour_index = n*(neighbour[0]-1) + neighbour[1] - 1
            if new_d < d[neighbour_index][0]:
                d[neighbour_index] = [new_d, neighbour_index]
                heapq.heappush(q, [new_d, neighbour_index])

    if t_found:
        return "YES"
    else:
        return "NO"








if __name__ == "__main__":
    n = 5
    q = 2
    r = [0, 6, 2, 7, 8, 3]
    c = [0, 3, 4, 8, 5, 1]
    sv = [2, 2]
    tv = [1, 3]

    sv = [4, 2] 
    tv = [4, 3]

    sv = [5, 1] 
    tv = [3, 4]

    res = even_earth(n, r, c, sv, tv)
    print(res)