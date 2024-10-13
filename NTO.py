from collections import defaultdict, deque

def longest_path(n, m, edges, S):
    graph = defaultdict(list)
    indegree = [0] * (n + 1)
    
    for A, B, d in edges:
        graph[A].append((B, d))
        indegree[B] += 1
    topo_order = []
    queue = deque()
    for i in range(1, n + 1):
        if indegree[i] == 0:
            queue.append(i)
    
    while queue:
        node = queue.popleft()
        topo_order.append(node)
        for neighbor, weight in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)
    if len(topo_order) < n:
        return [-1] * n
    dist = [-1] * (n + 1)
    dist[S] = 0  
    
    for node in topo_order:
        if dist[node] != -1:  
            for neighbor, weight in graph[node]:
                if dist[neighbor] < dist[node] + weight:
                    dist[neighbor] = dist[node] + weight
    
    return dist[1:]



   
n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]
S = int(input())
result = longest_path(n, m, edges, S)
print(' '.join(map(str, result)))
