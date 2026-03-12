# 🧩 Cycle Detection in an Undirected Graph (BFS)

**Difficulty:** Medium  
**LeetCode Link:** https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

---

## 🧠 Problem Statement

Given an **undirected graph with V vertices**, determine whether the graph contains a **cycle**.

The graph may be **disconnected**, meaning multiple components can exist.  
Your task is to check whether **any component** of the graph contains a cycle.

A cycle occurs when you can start from a node and return to the same node through a sequence of edges without repeating an edge.

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

The edge `4 → 1` creates a loop:  
1 → 2 → 3 → 4 → 1

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

The graph is a straight chain and does not contain any cycle.

---

## 💡 Intuition

In an **undirected graph**, simply encountering a visited node during traversal does not always indicate a cycle.  
It could just be the **parent node** from which we arrived.

To correctly detect cycles, we track the **parent of every node during BFS**.

If we encounter a **visited neighbor that is not the parent**, it means there is another path to reach that node, which forms a **cycle**.

Since the graph can be disconnected, we run BFS from **every unvisited node**.

---

## ⚙️ Algorithm

1. Convert the edge list into an **adjacency list**.
2. Maintain a **parent array** initialized with `-1`.
3. Iterate through all vertices.
4. If a vertex is unvisited:
   - Start **BFS** from that vertex.
5. During BFS:
   - Mark the parent of the node.
   - Push neighbors into the queue.
6. If a neighbor is already visited and **not equal to the parent**, a **cycle exists**.
7. If BFS finishes without detecting a cycle, return **false**.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:

    bool c(vector<vector<int>>& adj, vector<int>& par, int src) {

        queue<int> q;
        q.push(src);
        par[src] = src;

        while (!q.empty()) {

            int front = q.front();
            q.pop();

            for (auto& node : adj[front]) {

                if (par[node] == -1) {
                    par[node] = front;
                    q.push(node);
                }

                else if (node != par[front]) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V); 
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> par(V, -1);

        for (int src = 0; src < V; src++) {

            if (par[src] == -1) {
                if (c(adj, par, src)) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(V + E)  
Every vertex and edge is processed once during BFS.

**Space Complexity:** O(V)  
Queue and parent array store vertices during traversal.

---

## 🏷 Tags

- Graph
- Breadth First Search (BFS)
- Cycle Detection
- Undirected Graph
- Queue
- Graph Traversal