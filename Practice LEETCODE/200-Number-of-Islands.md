
# 🧩 200. Number of Islands

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/number-of-islands/

---

## 🧠 Problem Statement

Given an **m x n 2D grid** where each cell represents either:

- `'1'` → Land  
- `'0'` → Water  

Return the **number of islands**.

An island is surrounded by water and is formed by connecting adjacent lands **horizontally or vertically**.  
You may assume all four edges of the grid are surrounded by water.

---

## 📌 Examples

### Example 1

Input

```
grid =
[
 ["1","1","1","1","0"],
 ["1","1","0","1","0"],
 ["1","1","0","0","0"],
 ["0","0","0","0","0"]
]
```

Output

```
1
```

Explanation  
All land cells are connected, forming a single island.

---

### Example 2

Input

```
grid =
[
 ["1","1","0","0","0"],
 ["1","1","0","0","0"],
 ["0","0","1","0","0"],
 ["0","0","0","1","1"]
]
```

Output

```
3
```

Explanation  
There are three separate islands.

---

## 💡 Intuition

Whenever we encounter a **land cell ('1')**, it means we have discovered a new island.

To avoid counting the same island multiple times, we perform a **Depth First Search (DFS)** from that cell and mark all connected land cells as **visited**.

We mark visited land by converting `'1'` into `'0'`.  
This ensures that the same island is not explored again.

---

## ⚙️ Algorithm

1. Traverse each cell in the grid.
2. If the current cell is `'1'`:
   - Increase the island counter.
   - Start a **DFS traversal**.
3. During DFS:
   - Check boundary conditions.
   - If the cell is not land, stop recursion.
4. Mark the current land cell as `'0'`.
5. Recursively explore its **4 neighbors**:
   - Up
   - Down
   - Left
   - Right
6. Continue until the entire island is marked visited.
7. Repeat for all cells.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:

    void c(int i, int j, vector<vector<char>>& grid){

        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return;

        grid[i][j] = '0';

        c(i+1, j, grid);
        c(i-1, j, grid);
        c(i, j+1, grid);
        c(i, j-1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == '1'){
                    count++;
                    c(i,j,grid);
                }

            }
        }

        return count;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(m × n)  
Every cell in the grid is visited at most once.

**Space Complexity:** O(m × n)  
In the worst case, recursion stack may grow up to the size of the grid.

---

## 🏷 Tags

- Graph
- Depth First Search (DFS)
- Matrix
- Flood Fill
- Graph Traversal