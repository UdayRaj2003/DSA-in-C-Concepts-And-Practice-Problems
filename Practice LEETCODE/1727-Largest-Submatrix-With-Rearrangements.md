 
# 🧩 1727. Largest Submatrix With Rearrangements

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/largest-submatrix-with-rearrangements/

---

## 🧠 Problem Statement

You are given a binary matrix of size **m x n**.

You are allowed to **rearrange the columns** of the matrix in any order.

Return the **area of the largest submatrix** consisting only of `1`s after rearranging the columns optimally.

---

## 📌 Examples

### Example 1

Input

```
matrix = [[0,0,1],
          [1,1,1],
          [1,0,1]]
```

Output

```
4
```

Explanation

After rearranging columns optimally, we can form a submatrix of size 2 × 2 consisting of all 1s.

---

### Example 2

Input

```
matrix = [[1,0,1,0,1]]
```

Output

```
3
```

---

## 💡 Intuition

We treat each row as a **histogram**, where each column stores the height of consecutive `1`s ending at that row.

Since we are allowed to rearrange columns:
- We can **sort the heights in descending order**
- This helps maximize the width for larger heights

Then for each position:
```
Area = height × width
```

This gives the largest possible submatrix at that row.

---

## ⚙️ Algorithm

1. Initialize a `height` array of size `n` with all zeros.
2. Traverse each row:
   - If `matrix[i][j] == 1`, increment `height[j]`
   - Else reset `height[j] = 0`
3. Copy `height` into a temporary array.
4. Sort the temporary array in **descending order**.
5. For each column `j`:
   - Compute area = `temp[j] * (j + 1)`
   - Update maximum area.
6. Return the maximum area found.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> height(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1)
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            
            vector<int> temp = height;
            sort(temp.begin(), temp.end(), greater<int>());

            for (int j = 0; j < n; j++) {
                int area = temp[j] * (j + 1);
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(m × n log n)  
Sorting each row takes `O(n log n)`.

**Space Complexity:** O(n)  
Extra space used for height and temporary arrays.

---

## 🏷 Tags

- Greedy
- Matrix
- Sorting
- Histogram
- Arrays
```