# 🧩 785. Is Graph Bipartite?

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/is-graph-bipartite/

---

## 🧠 Problem Statement

Given an **undirected graph**, return **true** if and only if it is **bipartite**.

A graph is bipartite if the nodes can be divided into **two disjoint sets** such that:

- Every edge connects a node from one set to a node in the other set
- No two adjacent nodes belong to the same set

The graph is given as an adjacency list:

```
graph[i] contains all nodes connected to node i
```

---

## 📌 Examples

### Example 1

Input

```
graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
```

Output

```
false
```

Explanation  
There exists an odd-length cycle, so it cannot be divided into two sets.

---

### Example 2

Input

```
graph = [[1,3],[0,2],[1,3],[0,2]]
```

Output

```
true
```

Explanation  
The graph can be divided into two groups such that no adjacent nodes are in the same group.

---

## 💡 Intuition

To check if a graph is bipartite, we try to **color the graph using two colors**.

- Start BFS from an unvisited node
- Assign it a color (0 or 1)
- Assign all its neighbors the opposite color
- Continue this process

If at any point, a neighbor has the **same color as the current node**, the graph is **not bipartite**.

---

## ⚙️ Algorithm

1. Initialize a color array `col` with `-1` (unvisited).
2. Traverse all nodes:
   - If a node is unvisited, start BFS.
3. In BFS:
   - Assign the starting node a color.
   - For each neighbor:
     - If unvisited → assign opposite color and push to queue
     - If already visited and same color → return false
4. If all nodes are processed without conflict, return true.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool c(vector<vector<int>>& g, int src, vector<int>& col) {
        queue<int> q;

        bool color = 0;
        q.push(src);
        col[src] = 0;
        while (!q.empty()) {
            int front = q.front();
            q.pop();
            for (auto nbr : g[front]) {
                if (col[nbr] == -1) {
                    col[nbr] = !col[front];
                    q.push(nbr);
                } else if (col[nbr] != -1) {
                    if (col[nbr] == col[front]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(), -1);
        bool ans = true;
        for (int i = 0; i < graph.size(); i++) {
            if (col[i] == -1) {
                ans &= c(graph, i, col);
            }
        }
        return ans;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(V + E)  
Each node and edge is visited once.

**Space Complexity:** O(V)  
For the color array and BFS queue.

---

## 🏷 Tags

- Graph
- Breadth First Search (BFS)
- Bipartite Graph
- Coloring
- Graph Traversal
```