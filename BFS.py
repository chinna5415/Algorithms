def bfs(adj , visited , s , queue):
    queue.append(s)
    while len(queue) != 0:
        visited.append(queue[0])
        v = queue[0]
        queue.pop(0)
        
        for i in range(len(adj)):
            if adj[v][i] == 1:
                if (i in visited) or (i in queue):
                    continue
                else :
                    queue.append(i)
    
adj = [[0,1,1,0],[1,0,1,1],[1,1,0,1],[0,1,1,0]]
visited = []
queue = []
s = 0

bfs(adj , visited , s , queue)

for i in range(len(adj)):
    print('->',chr(65+visited[i]),end = ' ')