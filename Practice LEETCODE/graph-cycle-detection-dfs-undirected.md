
# 🧩 Cycle Detection in an Undirected Graph (DFS)

**Difficulty:** Medium  
**gfg Link:** https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

---

## 🧠 Problem Statement

Given an **undirected graph with V vertices**, determine whether the graph contains a **cycle**.

The graph may contain **multiple disconnected components**.  
A cycle exists if there is a path that starts and ends at the same vertex without repeating edges.

Your task is to return **true if a cycle exists**, otherwise return **false**.

---

## 📌 Examples

### Example 1

Input

```
V = 5
Edges = [[0,1],[1,2],[2,3],[3,4],[4,1]]
```

Output

```
true
```

Explanation

The edges create the cycle:

```
1 → 2 → 3 → 4 → 1
```

---

### Example 2

Input

```
V = 4
Edges = [[0,1],[1,2],[2,3]]
```

Output

```
false
```

Explanation

The graph forms a simple chain and does not contain a cycle.

---

## 💡 Intuition

In an **undirected graph**, visiting an already visited node does not always indicate a cycle because it could simply be the **parent node** from which we arrived.

To detect cycles correctly during **DFS traversal**, we track the **parent of each node**.  
If we encounter a visited node that is **not the parent**, it means another path reached that node, which forms a cycle.

Since the graph may be disconnected, we run DFS from **every unvisited vertex**.

---

## ⚙️ Algorithm

1. Convert the edge list into an **adjacency list**.
2. Create a **parent array** initialized with `-1`.
3. Iterate through each vertex from `0 → V-1`.
4. If the vertex is unvisited:
   - Mark it as its own parent.
   - Start **DFS traversal**.
5. For each adjacent node:
   - If it is unvisited, assign its parent and recursively call DFS.
   - If it is visited and **not equal to the parent**, a cycle exists.
6. If any DFS call detects a cycle, return **true**.
7. If all components are explored without detecting a cycle, return **false**.

---

## 💻 Solution (C++)

```cpp
class Solution {
  public:

    bool dfs(int node , vector<vector<int>>& adj, vector<int>& par){
        
        for(auto &adjnode : adj[node]){
            
            if(par[adjnode] == -1){
                par[adjnode] = node;

                if(dfs(adjnode,adj,par))
                    return true;
            }
            else if(adjnode != par[node]){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> par(V,-1);

        for(int src=0; src<V; src++){

            if(par[src] == -1){

                par[src] = src;

                if(dfs(src,adj,par))
                    return true;
            }
        }

        return false;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(V + E)  
Each vertex and edge is visited once during DFS.

**Space Complexity:** O(V)  
The recursion stack and parent array store vertices during traversal.

---

## 🏷 Tags

- Graph
- Depth First Search (DFS)
- Cycle Detection
- Undirected Graph
- Graph Traversal
- Recursion