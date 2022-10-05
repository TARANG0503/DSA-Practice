# Kahn's Algorithm is used in Directed Acyclic Graph to find Topological ordering 
def topologicalSort(l: int):
    indegree = [0] * len(l)
    queue = []
    topo = []
    cnt = 0

    for key, values in l.items():
        for i in values:
            indegree[i] += 1

    for i in range(len(indegree)):
        if indegree[i] == 0:
            queue.append(i)

    while(queue):
        vertex = queue.pop(0)
        cnt += 1
        topo.append(vertex)
        for x in l[vertex]:
            indegree[x] -= 1
            if indegree[x] == 0:
                queue.append(x)

    if cnt != len(l):
        print("Cycle exists")
    else:
        print(topo)

# Example of Adjacency List of Graph
l = {0:[1,2], 1:[3], 2:[3], 3:[4,5], 4:[], 5:[]}
topologicalSort(l)
