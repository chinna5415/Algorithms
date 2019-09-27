def dfs(adj , visited , s , stack):
    stack.append(s)
    
    while (len(stack) != 0):
        visited.append(stack[len(stack)-1])
        v = stack[len(stack)-1]
        stack.remove(stack[len(stack)-1])
        
        for i in range(len(adj)):
            if adj[v][i] == 1:
                if (i in visited) or (i in stack):
                    continue
                else :
                    stack.append(i)
 
adj = [[0,1,1,0],[1,0,1,1],[1,1,0,1],[0,1,1,0]]
visited = []
stack = []
s = 0

dfs(adj , visited , s , stack)

for i in range(len(adj)):
    print('->',chr(65+visited[i]),end = ' ')