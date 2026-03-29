# 🧩 Minimum Spanning Tree (Prim’s Algorithm)

**Difficulty:** Medium  
**LeetCode Link:** https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1

---

## 🧠 Problem Statement

Given a **weighted undirected graph** with `V` vertices and a list of edges:

```
edges[i] = [u, v, w]
```

Where:
- `u` and `v` are vertices
- `w` is the weight of the edge

Find the **sum of weights of the Minimum Spanning Tree (MST)**.

---

## 📌 Examples

### Example 1

Input

```
V = 3
edges = [[0,1,5],[1,2,3],[0,2,1]]
```

Output

```
4
```

Explanation  
The MST includes edges:
- (0,2) → weight 1  
- (1,2) → weight 3  

Total = 4

---

## 💡 Intuition

We want to connect all nodes with **minimum total weight** without forming cycles.

Using **Prim’s Algorithm**:
- Start from any node
- Always pick the smallest edge connecting a visited node to an unvisited node

This greedy strategy ensures optimal MST construction.

---

## ⚙️ Algorithm

1. Build adjacency list.
2. Use a **priority queue (min-heap)** storing `(weight, node)`.
3. Start from node `0` with weight `0`.
4. While queue is not empty:
   - Extract minimum edge
   - If node already visited → skip
   - Add weight to MST sum
   - Mark node as visited
   - Push all unvisited neighbors into queue
5. Return total weight.

---

## 💻 Solution (C++)

```cpp
class cmp {
public:
    bool operator()(const pair<int, pair<int, int>>& a,
                    const pair<int, pair<int, int>>& b) {
        if (a.first == b.first) {
            return a.second.first > b.second.first;
        }
        return a.first > b.first;
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& ed) {
        vector<int> vis(V, 0);
        vector<vector<pair<int,int>>> g(V);
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                        cmp>
            pq;
        pq.push({0, {0, -1}}); 
        int sum = 0;

        for (auto e : ed) {
            int u = e[0], v = e[1], w = e[2];
            g[v].push_back({u, w});
            g[u].push_back({v, w});
        }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second.first;
            if(vis[node]){
                continue;
            }
            sum += top.first;
            vis[node] = 1;
            for (auto i : g[node]) {
                if (!vis[i.first]) {
                    pq.push({i.second, {i.first, node}});
                }
            }
        }
        return sum;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O((V + E) log V)  
Priority queue operations dominate.

**Space Complexity:** O(V + E)  
Adjacency list and heap.

---

## 🏷 Tags

- Graph
- Greedy
- Minimum Spanning Tree
- Prim’s Algorithm
- Priority Queue
```