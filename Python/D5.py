n = int(input('Enter the number of vertices:\n'))
print('Enter the edges:')
edges = set()
for i in range(0, n-1):
    edges.add(frozenset(input().split()))
bfs = input('Enter the BFS:\n').split()

i=0
levels=[set(['1'])]
while len(edges)>0:
    next_level=set()
    used_edges=set()
    for edge in edges:
        if (not edge.isdisjoint(levels[i])):
            used_edges.add(edge)
            edge_copy = set(edge)
            v1 = edge_copy.pop()
            v2 = edge_copy.pop()
            if (v1 in levels[i]):
                next_level.add(v2)
            else:
                next_level.add(v1)
    for edge in used_edges:
        edges.remove(edge)
    levels.append(next_level)
    i= i + 1

for i in range(0, len(levels)):
    for j in range(0, len(levels[i])):
        if not bfs.pop(0) in levels[i]:
            print('NO')
            exit()
print('YES')