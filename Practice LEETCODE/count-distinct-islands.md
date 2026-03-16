# 🧩 Count Distinct Islands

**Difficulty:** Medium  
**LeetCode Link:** https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

---

## 🧠 Problem Statement

Given a **binary grid** where:

- `1` represents **land**
- `0` represents **water**

An island is a group of connected land cells connected **4-directionally**
(up, down, left, right).

Two islands are considered **distinct** if their **shapes are different**.
The position of the island does **not matter**, only the shape matters.

Return the **number of distinct islands**.

---

## 📌 Examples

### Example 1

Input

```
grid =
[
 [1,1,0,1,1],
 [1,0,0,0,0],
 [0,0,0,0,1],
 [1,1,0,1,1]
]
```

Output

```
3
```

Explanation

There are three unique island shapes present in the grid.

---

## 💡 Intuition

If we directly compare island coordinates, islands at different positions will appear different even if they have the same shape.

To solve this, we **normalize the island shape** by storing the **relative coordinates** of each cell with respect to the **starting cell of the island**.

For example:

```
(i, j) → starting cell
(i - base_i, j - base_j)
```

This representation ensures that two identical shapes produce the same relative coordinate pattern.

We store each island shape in a **set** to automatically remove duplicates.

---

## ⚙️ Algorithm

1. Traverse the entire grid.
2. Whenever a cell with value `1` is found:
   - Create an empty vector `shape`.
   - Start DFS from that cell.
3. During DFS:
   - Mark the cell as visited (`grid[i][j] = 0`).
   - Store the **relative position** `(i - base_i, j - base_j)` in `shape`.
4. Continue DFS in **four directions**.
5. After completing DFS for an island:
   - Insert the `shape` vector into a **set**.
6. The size of the set represents the **number of distinct island shapes**.

---

## 💻 Solution (C++)

```cpp
class Solution {
  public:

    void dfs(int i, int j, int base_i, int base_j,
             vector<vector<int>>& grid,
             vector<pair<int,int>>& shape){

        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return;

        grid[i][j] = 0;

        shape.push_back({i-base_i , j-base_j});

        dfs(i+1,j,base_i,base_j,grid,shape);
        dfs(i-1,j,base_i,base_j,grid,shape);
        dfs(i,j+1,base_i,base_j,grid,shape);
        dfs(i,j-1,base_i,base_j,grid,shape);
    }


    int countDistinctIslands(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        set<vector<pair<int,int>>> st;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){

                    vector<pair<int,int>> shape;

                    dfs(i,j,i,j,grid,shape);

                    st.insert(shape);
                }

            }
        }

        return st.size();
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(m × n log k)  
Each cell is visited once, and shapes are inserted into a set.

**Space Complexity:** O(m × n)  
For recursion stack and storing island shapes.

---

## 🏷 Tags

- Graph
- Depth First Search (DFS)
- Matrix
- Hashing
- Graph Traversal
- Set
- Shape Normalization