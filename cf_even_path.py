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
 
            # print(s)
 
 
 
    for i in range(1, n+1):
        for j in range(1, n+1):
            board[i][j] = r[i] + c[j]
 
    for i in range(1, n+1):
        s = ""
        for j in range(1, n+1):
            s = s + str(board[i][j]).rjust(3)
        # print(s)
 
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
 
    # # print(heapq.heappop(q))
 
    t_found = False
    while len(q) > 0:
        current_node = heapq.heappop(q)
 
        if current_node[1] == t_index:
            t_found = True
            break
 
        current_node_index = current_node[1]
        # print(f"current node index: {current_node_index}")
 
        neighbour_nodes = graph[current_node_index]
        # print(f"neighbour_nodes: {neighbour_nodes}")
 
        for neighbour in neighbour_nodes:
            # print(f"d[current_node_index]: {d[current_node_index]}")
            new_d = d[current_node_index][0] + 1
            neighbour_index = n*(neighbour[0]-1) + neighbour[1] - 1
            if new_d < d[neighbour_index][0]:
                d[neighbour_index] = [new_d, neighbour_index]
                heapq.heappush(q, [new_d, neighbour_index])
 
    if t_found:
        return "YES"
    else:
        return "NO"
 
 
def make_sectors(n, s):
    #print(f"make_sectors: {make_sectors}")
    sectors = []
 
    sector_min = None
    sector_max = None
    for i in range(n):
        if s[i] % 2 == 0:
            #print(f"s[{i}]: {s[i]}")
            if sector_min is None:
                sector_min = i
                continue
            if sector_min is not None:
                sector_max = i
        else:
            if sector_min is not None and sector_max is not None:
                sectors.append((sector_min, sector_max))
            if sector_min is not None and sector_max is None:
                sectors.append((sector_min, sector_min))
            sector_min = None
            sector_max = None
    return sectors
 
 
def even_path_v2(n, r, c, sv, tv):
 
    r_sectors = make_sectors(n, r)
    c_sectors = make_sectors(n, c)
 
    # print(r_sectors)
    # print(c_sectors)
 
    r_in_range = False
    c_in_range = False
    for rs in r_sectors:
        if sv[0]-1 >= rs[0] and tv[0]-1 <= rs[1]:
            r_in_range = True
            break
 
    for cs in c_sectors:
        if sv[1]-1 >= cs[0] and tv[1]-1 <= cs[1]:
            c_in_range = True
            break
    
    if r_in_range == True and c_in_range == True:
        return "YES"
    else:
        return "NO"
 
if __name__ == "__main__":
    # n = 5
    # q = 2
    # r = [6, 2, 7, 8, 3]
    # c = [3, 4, 8, 5, 1]
    # sv = [2, 2]
    # tv = [1, 3]
 
    # res = even_path_v2(n, r, c, sv, tv)
    # print(res)

    # sv = [4, 2] 
    # tv = [4, 3]

    # res = even_path_v2(n, r, c, sv, tv)
    # print(res)

    # sv = [5, 1] 
    # tv = [3, 4]
 
    # res = even_path_v2(n, r, c, sv, tv)
    # print(res)
 
    n, q = input().split(" ")
    n = int(n)
    q = int(q)
 
    r = input()
    r = r.split(" ")
    r = [int(i) for i in r]
 
 
    c = input()
    c = c.split(" ")
    c = [int(i) for i in c]
 
    for i in range(q):
        racarbcb = input().split(" ")
        ra = int(racarbcb[0])
        ca = int(racarbcb[1])
        rb = int(racarbcb[2])
        cb = int(racarbcb[3])
 
        res = even_path_v2(n, r, c, [ra, ca], [rb, cb])
        print(res)