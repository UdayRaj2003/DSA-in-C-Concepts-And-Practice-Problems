# 🧩 785. Is Graph Bipartite? (DFS Approach)

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/is-graph-bipartite/

---

## 🧠 Problem Statement

Given an **undirected graph**, determine whether it is **bipartite**.

A graph is bipartite if its nodes can be divided into **two sets** such that:

- No two adjacent nodes are in the same set
- Every edge connects nodes from different sets

The graph is provided as an adjacency list.

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
The graph contains an odd-length cycle.

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
The graph can be divided into two valid sets.

---

## 💡 Intuition

We try to color the graph using **two colors (0 and 1)**.

Using **DFS traversal**:
- Assign a color to the starting node
- Assign opposite colors to neighbors
- Continue recursively

If we encounter a node that is already colored and has the **same color as the current node**, the graph is **not bipartite**.

---

## ⚙️ Algorithm

1. Initialize a color array `col` with `-1`.
2. Traverse all nodes:
   - If a node is unvisited, assign a color and start DFS.
3. In DFS:
   - For each neighbor:
     - If unvisited → assign opposite color and recurse
     - If visited and same color → return false
4. If no conflicts occur, return true.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool dfs(vector<vector<int>>& g, int src, vector<int>& col) {
 
            for (auto nbr : g[src]) {
                if (col[nbr] == -1) {
                    col[nbr] = !col[src];
                    cout<<src<<"->"<<nbr<<endl;
                  if (!dfs(g, nbr, col)) return false;
                } else if (col[nbr] != -1) {
                    if (col[nbr] == col[src]) {
                        return false;
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
                bool color = 0;
                col[i] = 0;
                ans &= dfs(graph, i, col);
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
Due to recursion stack and color array.

---

## 🏷 Tags

- Graph
- Depth First Search (DFS)
- Bipartite Graph
- Coloring
- Graph Traversal
- Recursion