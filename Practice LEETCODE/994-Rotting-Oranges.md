
# 🧩 994. Rotting Oranges

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/rotting-oranges/

---

## 🧠 Problem Statement

You are given an **m x n grid** where each cell can have one of three values:

- **0** representing an empty cell  
- **1** representing a fresh orange  
- **2** representing a rotten orange  

Every minute, any fresh orange that is **4-directionally adjacent** (up, down, left, right) to a rotten orange becomes rotten.

Return the **minimum number of minutes** that must elapse until no cell has a fresh orange. If this is impossible, return **-1**.

---

## 📌 Examples

### Example 1

Input:
```
grid = [[2,1,1],[1,1,0],[0,1,1]]
```

Output:
```
4
```

Explanation:  
The rotting spreads from the initial rotten orange and eventually infects all fresh oranges in 4 minutes.

---

### Example 2

Input:
```
grid = [[2,1,1],[0,1,1],[1,0,1]]
```

Output:
```
-1
```

Explanation:  
The orange at position `(2,0)` can never become rotten because there is no path from any rotten orange.

---

### Example 3

Input:
```
grid = [[0,2]]
```

Output:
```
0
```

Explanation:  
There are no fresh oranges initially, so the time required is `0`.

---

## 💡 Intuition

The rotting process spreads outward from already rotten oranges. This is similar to how infection spreads in waves.

To simulate this process efficiently, we use **Breadth First Search (BFS)**. All rotten oranges are added to a queue initially. Each BFS level represents one minute of spreading. When a rotten orange infects its neighboring fresh oranges, those newly rotten oranges are added to the queue for the next minute.

---

## ⚙️ Algorithm

1. Traverse the grid and:
   - Push all rotten oranges into a queue.
   - Count the total number of fresh oranges.

2. If there are no fresh oranges, return `0`.

3. Perform **BFS**:
   - Process all oranges currently in the queue.
   - For each rotten orange, check its 4 neighbors.
   - If a neighbor is fresh:
     - Turn it rotten.
     - Decrease the fresh count.
     - Push it into the queue.

4. Each BFS level represents **1 minute**.

5. Continue until the queue becomes empty.

6. If fresh oranges still remain, return `-1`.

7. Otherwise, return the total minutes.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        int minutes = 0;

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){

            int size = q.size();
            bool rotten = false;

            for(int k = 0; k < size; k++){

                auto front = q.front();
                q.pop();

                int i = front.first;
                int j = front.second;

                for(int d = 0; d < 4; d++){

                    int ni = i + dir[d][0];
                    int nj = j + dir[d][1];

                    if(ni >= 0 && nj >= 0 && ni < row && nj < col && grid[ni][nj] == 1){

                        grid[ni][nj] = 2;
                        fresh--;
                        q.push({ni,nj});
                        rotten = true;
                    }
                }
            }

            if(rotten) minutes++;
        }

        if(fresh > 0) return -1;

        return minutes;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(m × n)  
Each cell is processed at most once during BFS.

**Space Complexity:** O(m × n)  
In the worst case, the queue may store all cells of the grid.

---

## 🏷 Tags

- Breadth First Search (BFS)
- Graph Traversal
- Matrix
- Simulation
- Queue