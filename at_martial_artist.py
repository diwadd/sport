n = int(input())

graph = []

class Node:
    def __init__(self, id, t, seq):
        self.id = id
        self.t = t
        self.seq = seq
        self.visited = False

    def __str__(self):
        return f"{self.id} {self.t} {self.visited} {self.seq}"

    def __repr__(self):
        return self.__str__()

for id in range(n):
    tkseq = input().split(" ")

    t = int(tkseq[0])
    k = int(tkseq[1])
    seq = tkseq[2:]
    seq = [int(s) - 1 for s in seq]

    graph.append(Node(id, t, seq))


q = []
graph[-1].visited = True
q.append(graph[-1])

t = 0
while len(q) > 0:
    node = q.pop()

    t += node.t

    for s in node.seq:
        if graph[s].visited == False:
            graph[s].visited = True
            q.append(graph[s])

print(t)