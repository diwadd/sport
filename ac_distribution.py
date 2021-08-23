import math
import heapq
    
class Edge:
    def __init__(self, s, t, d):
        self.source = s
        self.target = t
        self.distance = d
    
    def __str__(self) -> str:
        return f"{self.source}->{self.target} ({self.distance})"
    
    def __repr__(self) -> str:
        return self.__str__()
    
def read_list_of_ints():
    return [int(d) for d in input().split(" ")]
    
n = int(input())
    
s_vec = read_list_of_ints()
t_vec = read_list_of_ints()
    
graph = [[] for _ in range(n+1)]
    
for i in range(n):
    graph[0].append(Edge(0, i+1, t_vec[i]))
    
for i in range(n-1):
    graph[i+1].append(Edge(i+1, i+2, s_vec[i]))
    
graph[n].append(Edge(i-1, 1, s_vec[n-1]))
    
def get_closest_vertex_index(distance: list, visited: list) -> int:
    
    min_d = math.inf
    index = None
    for i in range(len(distance)):
        if visited[i] == True:
            continue
    
        d = distance[i]
        if d < min_d:
            min_d = d
            index = i
    return index
    
def find_distance(source: int, target: int) -> int:
    
    distance = [math.inf for _ in range(n+1)]
    distance[0] = 0
    
    visited = [False for _ in range(n+1)]
    
    n_visited = 0
    while n_visited <= n+1:
    
        index = get_closest_vertex_index(distance, visited)
    
        if index == target:
            return distance[target]
    
        visited[index] = True
        n_visited += 1
    
        for u in graph[index]:
            d = distance[index] + u.distance
            if d < distance[u.target]:
                distance[u.target] = d
    
    
def find_distance_faster(source: int, target: int) -> int:
    
    distance = [math.inf for _ in range(n+1)]
    distance[0] = 0
    q = [(0, 0)]
    heapq.heapify(q)
    
    while len(q) > 0:
    
        v = q[0]
        heapq.heappop(q)
        index = v[1]        
    
        if index == target:
            return distance[target]
    
        for u in graph[index]:
            d = v[0] + u.distance
            if d < distance[u.target]:
                distance[u.target] = d
                heapq.heappush(q, (d, u.target))
    
res = []
for i in range(1, n+1):
    res.append(str(find_distance_faster(source=0, target=i)))
    
print(" ".join(res))