# Graph Algorithms Cheat Sheet (DSA)

| Algorithm                              | Type                    | Why Needed / Use Case                                      | Time Complexity                     | Limitations                                                              |
| -------------------------------------- | ----------------------- | ---------------------------------------------------------- | ----------------------------------- | ------------------------------------------------------------------------ |
| [**DFS (Depth First Search)** ](#1-dfs-depth-first-search)          | Traversal               | Explore all nodes, detect cycles, connected components     | `O(V + E)`                          | Can cause stack overflow (deep recursion), not optimal for shortest path |
| [**BFS (Breadth First Search)**](#2-bfs-breadth-first-search)         | Traversal               | Shortest path in **unweighted graph**                      | `O(V + E)`                          | Not suitable for weighted graphs                                         |
| **Dijkstra’s Algorithm**               | Shortest Path           | Shortest path in **weighted graph (non-negative weights)** | `O((V + E) log V)` (with PQ)        | Fails with negative weights                                              |
| **Bellman-Ford**                       | Shortest Path           | Works with **negative weights**, detects negative cycles   | `O(V * E)`                          | Slower than Dijkstra                                                     |
| **Floyd-Warshall**                     | All-Pairs Shortest Path | Find shortest paths between all pairs, detect negative cycle                      | `O(V³)`                             | Not scalable for large graphs                                            |
| **Topological Sort (Kahn’s / DFS)**    | DAG                     | Order tasks with dependencies (e.g., scheduling)           | `O(V + E)`                          | Works only for DAG (fails if cycle exists)                               |
| **Kahn’s Algorithm**                   | Topological Sort        | BFS-based topo sort                                        | `O(V + E)`                          | Detects cycle indirectly                                                 |
| **Cycle Detection (DFS/BFS)**          | Utility                 | Detect cycles in directed/undirected graphs                | `O(V + E)`                          | Needs modification for directed vs undirected                            |
| **Union-Find (Disjoint Set)**          | Connectivity            | Efficient cycle detection, connected components            | `O(α(N)) ≈ O(1)`                    | Doesn’t store full graph structure                                       |
| **Kruskal’s Algorithm**                | MST                     | Minimum Spanning Tree using edges sorting                  | `O(E log E)`                        | Needs Union-Find, not ideal for dense graphs                             |
| **Prim’s Algorithm**                   | MST                     | MST using priority queue (good for dense graphs)           | `O((V + E) log V)`                  | Requires adjacency structure                                             |
| **Kosaraju’s Algorithm**               | SCC                     | Find strongly connected components                         | `O(V + E)`                          | Requires 2 DFS passes                                                    |
| **Tarjan’s Algorithm**                 | SCC / Bridges           | Find SCC, bridges, articulation points                     | `O(V + E)`                          | Complex to implement                                                     |
| **Bridge Finding**                     | Critical Edges          | Find edges whose removal disconnects graph                 | `O(V + E)`                          | Requires DFS + low-link logic                                            |
| **Articulation Points**                | Critical Nodes          | Find nodes whose removal disconnects graph                 | `O(V + E)`                          | Same complexity as Tarjan                                                |
| **0-1 BFS**                            | Shortest Path           | Graph with weights {0,1}                                   | `O(V + E)`                          | Only works for 0/1 weights                                               |
| **Multi-source BFS**                   | Shortest Path           | Distance from multiple sources (e.g., nearest hospital)    | `O(V + E)`                          | Only for unweighted graphs                                               |
| **A* Algorithm**                       | Shortest Path           | Optimized pathfinding with heuristics (games/maps)         | `O(E)` (depends on heuristic)       | Requires good heuristic                                                  |
| **Bidirectional BFS**                  | Search                  | Faster search between two nodes                            | `O(V + E)` (but faster in practice) | Harder to implement                                                      |
| **Eulerian Path/Circuit (Hierholzer)** | Path                    | Visit every edge exactly once                              | `O(V + E)`                          | Requires degree conditions                                               |
| **Hamiltonian Path**                   | Path                    | Visit every node exactly once                              | `O(N!)`                             | NP-hard                                                                  |
| **Ford-Fulkerson**                     | Max Flow                | Maximum flow in network                                    | `O(E * max_flow)`                   | Can be slow                                                              |
| **Edmonds-Karp**                       | Max Flow                | BFS-based Ford-Fulkerson                                   | `O(V * E²)`                         | Still slow for large graphs                                              |
| **Dinic’s Algorithm**                  | Max Flow                | Optimized max flow                                         | `O(E * sqrt(V))` or better          | Complex implementation                                                   |
| **Hopcroft-Karp**                      | Bipartite Matching      | Maximum matching in bipartite graph                        | `O(√V * E)`                         | Only for bipartite graphs                                                |


## Java Snippets

### 1. DFS (Depth First Search)

```java
void dfs(int node, List<List<Integer>> graph, boolean[] vis) {
    vis[node] = true;
    for (int nei : graph.get(node)) {
        if (!vis[nei]) dfs(nei, graph, vis);
    }
}
```

### 2. BFS (Breadth First Search)
```java
void bfs(int start, List<List<Integer>> graph) {
    Queue<Integer> q = new LinkedList<>();
    boolean[] vis = new boolean[graph.size()];
    
    q.add(start);
    vis[start] = true;

    while (!q.isEmpty()) {
        int node = q.poll();
        for (int nei : graph.get(node)) {
            if (!vis[nei]) {
                vis[nei] = true;
                q.add(nei);
            }
        }
    }
}
```

### 3. Dijkstra (Shortest Path)
```java
int[] dijkstra(int n, List<List<int[]>> graph, int src) {
    PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[1]-b[1]);
    int[] dist = new int[n];
    Arrays.fill(dist, Integer.MAX_VALUE);
    
    pq.add(new int[]{src, 0});
    dist[src] = 0;

    while (!pq.isEmpty()) {
        int[] curr = pq.poll();
        int node = curr[0], d = curr[1];

        for (int[] nei : graph.get(node)) {
            int next = nei[0], w = nei[1];
            if (d + w < dist[next]) {
                dist[next] = d + w;
                pq.add(new int[]{next, dist[next]});
            }
        }
    }
    return dist;
}
```

### 4. Bellman-Ford
```java
int[] bellmanFord(int n, int[][] edges, int src) {
    int[] dist = new int[n];
    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != Integer.MAX_VALUE && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}
```

### 5. Floyd-Warshall
```java
int INF = Integer.MAX_VALUE;
for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(dist[i][k]==INF || dist[k][j]==INF) continue;
            dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

// Negative cycle check
for (int i = 0; i < V; i++) {
    if (dist[i][i] < 0) {
        System.out.println("Negative cycle exists");
    }
}
```

### 6. Topological Sort (DFS)
```java
void topoDFS(int node, boolean[] vis, Stack<Integer> st, List<List<Integer>> g) {
    vis[node] = true;
    for (int nei : g.get(node)) {
        if (!vis[nei]) topoDFS(nei, vis, st, g);
    }
    st.push(node);
}
```

### 7. Kahn’s Algorithm (BFS Topo)
```java
Queue<Integer> q = new LinkedList<>();
for (int i = 0; i < n; i++) if (indegree[i] == 0) q.add(i);

while (!q.isEmpty()) {
    int node = q.poll();
    for (int nei : graph.get(node)) {
        if (--indegree[nei] == 0) q.add(nei);
    }
}
```

### 8. Union-Find (Disjoint Set)
```java
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void union(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa != pb) parent[pa] = pb;
}
```

### 9. Kruskal (MST)
```java
Arrays.sort(edges, (a,b) -> a[2] - b[2]);
for (int[] e : edges) {
    if (find(e[0]) != find(e[1])) {
        union(e[0], e[1]);
        cost += e[2];
    }
}
```

### 10. Prim’s Algorithm
```java
PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[1]-b[1]);
pq.add(new int[]{0, 0});
boolean[] vis = new boolean[n];

while (!pq.isEmpty()) {
    int[] curr = pq.poll();
    int node = curr[0], wt = curr[1];
    if (vis[node]) continue;
    vis[node] = true;
    cost += wt;

    for (int[] nei : graph.get(node)) {
        if (!vis[nei[0]]) pq.add(nei);
    }
}
```

### 11. Cycle Detection (DFS - Undirected)
```java
boolean dfs(int node, int parent, boolean[] vis, List<List<Integer>> g) {
    vis[node] = true;
    for (int nei : g.get(node)) {
        if (!vis[nei]) {
            if (dfs(nei, node, vis, g)) return true;
        } else if (nei != parent) return true;
    }
    return false;
}
```

### 12. Tarjan’s (Bridges)
```java
void dfs(int u, int p) {
    disc[u] = low[u] = ++time;
    for (int v : graph.get(u)) {
        if (v == p) continue;
        if (disc[v] == 0) {
            dfs(v, u);
            low[u] = Math.min(low[u], low[v]);
            if (low[v] > disc[u]) bridges.add(Arrays.asList(u, v));
        } else {
            low[u] = Math.min(low[u], disc[v]);
        }
    }
}
```

### 13. Kosaraju (SCC)

```java
// 1st DFS (fill stack)
void dfs1(int u) {
    vis[u] = true;
    for (int v : graph.get(u)) if (!vis[v]) dfs1(v);
    st.push(u);
}

// 2nd DFS (transpose)
void dfs2(int u, List<List<Integer>> rev) {
    vis[u] = true;
    for (int v : rev.get(u)) if (!vis[v]) dfs2(v, rev);
}
```

### 14. 0-1 BFS

```java
Deque<Integer> dq = new ArrayDeque<>();
dq.add(src);
dist[src] = 0;

while (!dq.isEmpty()) {
    int node = dq.pollFirst();
    for (int[] nei : graph.get(node)) {
        int v = nei[0], w = nei[1];
        if (dist[node] + w < dist[v]) {
            dist[v] = dist[node] + w;
            if (w == 0) dq.addFirst(v);
            else dq.addLast(v);
        }
    }
}
```

### 15. Multi-source BFS

```java
Queue<Integer> q = new LinkedList<>();
for (int src : sources) {
    q.add(src);
    dist[src] = 0;
}

while (!q.isEmpty()) {
    int node = q.poll();
    for (int nei : graph.get(node)) {
        if (dist[nei] == -1) {
            dist[nei] = dist[node] + 1;
            q.add(nei);
        }
    }
}
```

### 16. Bipartite Check (BFS)

```java
Queue<Integer> q = new LinkedList<>();
color[src] = 0;
q.add(src);

while (!q.isEmpty()) {
    int node = q.poll();
    for (int nei : graph.get(node)) {
        if (color[nei] == -1) {
            color[nei] = 1 - color[node];
            q.add(nei);
        } else if (color[nei] == color[node]) return false;
    }
}
```

### 17. Ford-Fulkerson (Basic DFS)

```java
int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    for (int v : graph.get(u)) {
        if (cap[u][v] > 0 && !vis[v]) {
            int pushed = dfs(v, t, Math.min(flow, cap[u][v]));
            if (pushed > 0) {
                cap[u][v] -= pushed;
                cap[v][u] += pushed;
                return pushed;
            }
        }
    }
    return 0;
}
```

### 18. Hopcroft-Karp (Core BFS Layering)

```java
boolean bfs() {
    Queue<Integer> q = new LinkedList<>();
    for (int u : leftSet) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            q.add(u);
        } else dist[u] = INF;
    }

    while (!q.isEmpty()) {
        int u = q.poll();
        for (int v : adj[u]) {
            if (dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                q.add(pairV[v]);
            }
        }
    }
    return dist[NIL] != INF;
}
```