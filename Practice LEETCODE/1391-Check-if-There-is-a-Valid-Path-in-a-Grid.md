# 🧩 1391. Check if There is a Valid Path in a Grid

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

---

## 🧠 Problem Statement

Given an `m x n` grid where each cell contains a street type from `1` to `6`.

Each street type connects to specific directions:

- Type 1 → left, right
- Type 2 → up, down
- Type 3 → left, down
- Type 4 → right, down
- Type 5 → left, up
- Type 6 → right, up

Return **true** if there is a valid path from the top-left cell `(0,0)` to the bottom-right cell `(m-1,n-1)`.

A path is valid only if adjacent cells have connected streets.

---

## 📌 Examples

### Example 1

Input

```text
grid = [[2,4,3],[6,5,2]]
```

Output

```text
true
```

Explanation

There exists a valid connected path from start to destination.

---

### Example 2

Input

```text
grid = [[1,2,1],[1,2,1]]
```

Output

```text
false
```

Explanation

The street connections do not form a valid path.

---

## 💡 Intuition

This is a graph traversal problem.

Each cell behaves like a node, and movement depends on the street type.

We use **BFS**:

- Start from `(0,0)`
- Move only in allowed directions
- Ensure the next cell also connects back to the current cell

If we reach the bottom-right cell, the answer is true.

---

## ⚙️ Algorithm

1. Store valid directions for each street type.
2. Start BFS from `(0,0)`.
3. For each current cell:
   - Try all allowed directions
4. For each neighbor:
   - Check bounds
   - Check if not visited
   - Verify neighbor connects back
5. If valid:
   - Mark visited
   - Push into queue
6. If destination reached → return true
7. Else → return false

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<vector<int>>> dir = {
            {},
            {{0, -1}, {0, 1}},
            {{-1, 0}, {1, 0}},
            {{0, -1}, {1, 0}},
            {{0, 1}, {1, 0}},
            {{0, -1}, {-1, 0}},
            {{0, 1}, {-1, 0}}
        };

        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (auto d : dir[grid[x][y]]) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny]) 
                    continue;

                for (auto back : dir[grid[nx][ny]]) {
                    if (nx + back[0] == x && ny + back[1] == y) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                        break;
                    }
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
Each cell is visited at most once.

**Space Complexity:** O(m × n)  
For visited matrix and BFS queue.

---

## 🏷 Tags

- Graph
- Breadth First Search (BFS)
- Matrix
- Grid Traversal
- Simulation
```