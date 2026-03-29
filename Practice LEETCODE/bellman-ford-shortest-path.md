# 🧩 Bellman-Ford Algorithm (Shortest Path with Negative Weights)

**Difficulty:** Medium  
**LeetCode Link:** https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

---

## 🧠 Problem Statement

Given a **weighted directed graph** with `V` vertices and `E` edges:

```
edges[i] = [u, v, w]
```

Where:
- `u → v` is a directed edge
- `w` is the weight (can be negative)

Find the **shortest distance from source node** to all other nodes.

If the graph contains a **negative weight cycle**, return `[-1]`.

---

## 📌 Examples

### Example 1

Input

```
V = 5
edges = [[0,1,5],[1,2,-2],[2,3,3],[3,1,1]]
src = 0
```

Output

```
[-1]
```

Explanation  
There is a negative cycle in the graph.

---

### Example 2

Input

```
V = 4
edges = [[0,1,1],[0,2,4],[1,2,-3],[2,3,2]]
src = 0
```

Output

```
[0,1,-2,0]
```

---

## 💡 Intuition

The shortest path can have at most **V-1 edges**.

So we:
- Relax all edges **V-1 times**
- Then check one more time:
  - If any edge can still be relaxed → **negative cycle exists**

This makes Bellman-Ford suitable for graphs with **negative weights**.

---

## ⚙️ Algorithm

1. Initialize distance array with large value (∞).
2. Set source distance to `0`.
3. Repeat V-1 times:
   - Relax all edges
4. Perform one extra iteration:
   - If any edge can still be relaxed → return `[-1]`
5. Return distance array.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

        vector<int> d(V, 1e8);
        d[src] = 0;
        int run = 0;
        while (run <= V) {
            for (auto e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (d[u] != 1e8 && d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    if (run == V) {
                        return {-1};
                    }
                }
            }
            run++;
        }

        return d;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(V × E)  
We relax all edges V times.

**Space Complexity:** O(V)  
For storing distances.

---

## 🏷 Tags

- Graph
- Bellman-Ford
- Shortest Path
- Dynamic Programming
- Negative Weights
- Cycle Detection
```