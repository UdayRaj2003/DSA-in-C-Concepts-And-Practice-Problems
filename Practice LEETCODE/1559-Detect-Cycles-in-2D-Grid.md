 # 🧩 1559. Detect Cycles in 2D Grid

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/detect-cycles-in-2d-grid/

---

## 🧠 Problem Statement

Given a **2D grid of characters**, determine if there exists a **cycle** in the grid.

A cycle is formed if:

- You start at a cell and move in **4 directions** (up, down, left, right)
- All visited cells have the **same character**
- You return to the starting cell
- The cycle length is at least **4**

---

## 📌 Examples

### Example 1

Input

```
grid = [
 ['a','a','a','a'],
 ['a','b','b','a'],
 ['a','b','b','a'],
 ['a','a','a','a']
]
```

Output

```
true
```

Explanation  
There exists a cycle formed by 'a' characters around the boundary.

---

### Example 2

Input

```
grid = [
 ['c','c','c','a'],
 ['c','d','c','c'],
 ['c','c','e','c'],
 ['f','c','c','c']
]
```

Output

```
true
```

---

### Example 3

Input

```
grid = [
 ['a','b','b'],
 ['b','z','b'],
 ['b','b','a']
]
```

Output

```
false
```

---

## 💡 Intuition

This problem is similar to **cycle detection in graphs**, but applied to a grid.

We use **DFS traversal** to explore connected components of the same character.

Key idea:
- Track the **parent cell** to avoid going back immediately
- If we encounter a **visited cell that is not the parent**, a cycle exists

---

## ⚙️ Algorithm

1. Create a visited matrix `vis`.
2. Traverse each cell in the grid.
3. If a cell is not visited:
   - Start DFS from that cell.
4. In DFS:
   - Mark the current cell as visited.
   - Explore 4-directional neighbors.
   - Skip the parent cell.
   - If a neighbor is already visited → cycle found.
5. If any DFS detects a cycle, return true.
6. If traversal completes without cycles, return false.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool dfs(int i, int j, int pi, int pj,
             vector<vector<char>>& g,
             vector<vector<bool>>& vis,
             int m, int n) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (vis[i][j])
            return true;

        vis[i][j] = true;

        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        for (auto &d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;

            if (ni == pi && nj == pj) continue;

            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                g[ni][nj] == g[i][j]) {

                if (dfs(ni, nj, i, j, g, vis, m, n))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& g) {
        int m = g.size(), n = g[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, g, vis, m, n))
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

**Time Complexity:** O(m × n)  
Each cell is visited once.

**Space Complexity:** O(m × n)  
Due to visited array and recursion stack.

---

## 🏷 Tags

- Graph
- Depth First Search (DFS)
- Matrix
- Cycle Detection
- Graph Traversal
- Recursion