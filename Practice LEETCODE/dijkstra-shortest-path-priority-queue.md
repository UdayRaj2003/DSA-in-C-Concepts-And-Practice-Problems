# 🧩 Dijkstra’s Algorithm (Shortest Path in Weighted Graph)

**Difficulty:** Medium  
**LeetCode Link:** https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

---

## 🧠 Problem Statement

Given a **weighted undirected graph** with `V` vertices and a list of edges:

```
edges[i] = [u, v, w]
```

Where:
- `u` and `v` are vertices
- `w` is the weight of the edge

Find the **shortest distance from a source node** to all other nodes.

---

## 📌 Examples

### Example 1

Input

```
V = 3
edges = [[0,1,1],[1,2,2],[0,2,4]]
src = 0
```

Output

```
[0,1,3]
```

Explanation  
Shortest path from 0 to:
- 1 → 1
- 2 → 1 + 2 = 3

---

## 💡 Intuition

We always want to expand the node with the **minimum current distance**.

Using a **min-heap (priority queue)**:
- Pick the closest node
- Relax its edges
- Update distances if a shorter path is found

This greedy strategy ensures correctness for graphs with **non-negative weights**.

---

## ⚙️ Algorithm

1. Build adjacency list from edges.
2. Initialize distance array with `INT_MAX`.
3. Set source distance to `0`.
4. Use a priority queue (min-heap).
5. While queue is not empty:
   - Pop node with smallest distance
   - Traverse neighbors
   - Relax edges (update distance if smaller path found)
6. Return distance array.

---

## 💻 Solution (C++)

```cpp
class cmp {
public:
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

class Solution {
  public:
  vector<int>c(int V, vector<vector<int>> &edges, int src){
      priority_queue<pair<int,int>,vector<pair<int,int>>, cmp>mp;
      vector<int>d(V,INT_MAX);
      vector<vector<pair<int,int>>>g(V);
      for(auto e: edges){
          g[e[0]].push_back({e[1],e[2]});
          g[e[1]].push_back({e[0],e[2]});
      }     
      d[src]=0;
      mp.push({src,0});
      while(!mp.empty()){
          auto src = mp.top();
          mp.pop();
            for(auto nbr : g[src.first] ){
            int node = nbr.first;
            int weight = nbr.second;
            int nbr_d = src.second+weight;
            if(d[node]>nbr_d){
                d[node] = nbr_d;
                mp.push({node,nbr_d});
                }
            }
      }
      return d;
      
  }
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        return c(V,edges,src);
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O((V + E) log V)  
Priority queue operations dominate.

**Space Complexity:** O(V + E)  
For adjacency list and distance array.

---

## 🏷 Tags

- Graph
- Dijkstra
- Greedy
- Priority Queue
- Shortest Path
- Heap
```