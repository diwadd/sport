import math
import heapq
import random

def make_graph(n, r, c):

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

    return graph


def even_path(n, r, c, sv, tv, graph):
 
    si = sv[0]
    sj = sv[1]
    ti = tv[0]
    tj = tv[1]
 
    s_index = n*(si-1) + sj - 1
    t_index = n*(ti-1) + tj - 1
 
    # Dijkstra algorithm - too slow
    n_vertices = len(graph)
    d = [[math.inf, i] for i in range(n_vertices)]
    p = [None for i in range(n_vertices)]
    q = []
    d[s_index][0] = 0
 
    heapq.heapify(q)
    heapq.heappush(q, [0,s_index])
 
    t_found = False
    while len(q) > 0:
        current_node = heapq.heappop(q)
 
        if current_node[1] == t_index:
            t_found = True
            break
 
        current_node_index = current_node[1]
        neighbour_nodes = graph[current_node_index]
 
        for neighbour in neighbour_nodes:
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
    sectors = []
 
    prev = s[0] % 2
    sector_min = prev


    for i in range(1, n):
        p = s[i] % 2

        if prev == p:
            continue
        else:
            sectors.append((sector_min, i))
            prev = p
            sector_min = i + 1

    if prev == p:
        sectors.append((sector_min, n))

    return sectors
 
 
def even_path_v2(n, r, c, sv, tv, r_sectors, c_sectors):
 
    r_a = sv[0]
    r_b = tv[0]

    c_a = sv[1]
    c_b = tv[1]

    # Linear search - too slow
    # for rs in r_sectors:

    #     r_a = sv[0]
    #     r_b = tv[0]

    #     r_min = rs[0]
    #     r_max = rs[1]

    #     if (r_min <= r_a and r_a <= r_max) and (r_min <= r_b and r_b <= r_max):
    #         r_in_range = True
    #         break


    # for cs in c_sectors:

    #     c_a = sv[1]
    #     c_b = tv[1]

    #     c_min = cs[0]
    #     c_max = cs[1]

    #     if (c_min <= c_a and c_a <= c_max) and (c_min <= c_b and c_b <= c_max):
    #         c_in_range = True
    #         break
    
    # Binary search - too slow
    r_in_range = bs_sectors([r_a, r_b], r_sectors)
    c_in_range = bs_sectors([c_a, c_b], c_sectors)

    if r_in_range == True and c_in_range == True:
        return "YES"
    else:
        return "NO"
 

def bs_sectors(target, sectors):

    n = len(sectors)
    f = target[0]
    s = target[1]

    left = 0
    right = n - 1

    while left <= right:

        mid = math.floor((right + left)/2)
        el = sectors[mid]

        e_min = el[0]
        e_max = el[1]

        if (e_min <= f and f <= e_max) and (e_min <= s and s <= e_max):
            return True
        elif f > e_max and s > e_max:
            left = mid + 1
        elif f < e_min and s < e_min:
            right = mid - 1
        else:
            return False

    return False

def mark_sectors(n, s):
    marks = [0 for i in range(n + 1)]

    current_mark = 0
    prev = s[0] % 2

    for i in range(1, n):
        p = s[i] % 2

        if prev == p:
            marks[i+1] = current_mark
        else:
            current_mark += 1
            prev = p
            marks[i+1] = current_mark

    return marks


def even_path_v3(n, sv, tv, r_marks, c_marks):
 
    r_a = sv[0]
    r_b = tv[0]

    c_a = sv[1]
    c_b = tv[1]
    
    # print(f"r_marks: {r_marks} c_marks: {c_marks}")
    # print(f"sv: {sv} st: {tv}")
    # print(f"{r_marks[r_a]} == {r_marks[r_b]}")
    # print(f"{c_marks[c_a]} == {c_marks[c_b]}")

    if r_marks[r_a] == r_marks[r_b] and c_marks[c_a] == c_marks[c_b]:
        return "YES"
    else:
        return "NO"
 

if __name__ == "__main__":


    # n = 5
    # q = 1

    # r = [1, 3, 5, 6, 8]
    # c = [1, 0, 3, 5, 7]

    # r = [6, 2, 7, 8, 3]
    # c = [3, 4, 8, 5, 1]

    # print(mark_sectors(n, r))
    # print(mark_sectors(n, c))

    # sv = [2, 2]
    # tv = [1, 3]
    
    # res = even_path_v3(n, sv, tv, mark_sectors(n, r), mark_sectors(n, c))
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

    r_marks = mark_sectors(n, r)
    c_marks = mark_sectors(n, c)

    for i in range(q):
        racarbcb = input().split(" ")
        ra = int(racarbcb[0])
        ca = int(racarbcb[1])
        rb = int(racarbcb[2])
        cb = int(racarbcb[3])
 
        res = even_path_v3(n, [ra, ca], [rb, cb], r_marks, c_marks)
        print(res)