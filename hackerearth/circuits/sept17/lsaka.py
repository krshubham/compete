import math
import sys

def dfs(current,parent):
    x = colors[current]
    # print current
    if sizes[x]>=k:
        ans[current] = cq[x][sizes[x]-k]
    cq[x].append(current)
    sizes[x] += 1
    for child in graph[current]:
        if child != parent:
            dfs(child,current)
    cq[x].pop()
    sizes[x] -= 1



n,k = map(int,raw_input().split())
#we gonna start from 1
colors = [0]+map(int,raw_input().split())
#cool is python ;)
graph = [[] for i in range(n+1)]

for i in range(n-1):
    a,b = map(int,raw_input().split())
    graph[a].append(b)
    graph[b].append(a)

cq = [[] for i in range(max(colors)+1)]
sizes = [0 for i in range(max(colors)+1)]
ans = [-1 for i in range(n+1)]

dfs(1,0)
for i in ans[1:]:
    print i,
print ""