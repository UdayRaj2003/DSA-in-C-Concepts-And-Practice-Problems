
# 🧩 1886. Determine Whether Matrix Can Be Obtained By Rotation

**Difficulty:** Easy  
**LeetCode Link:** https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

---

## 🧠 Problem Statement

Given two **n x n binary matrices** `mat` and `target`, return **true** if it is possible to make `mat` equal to `target` by rotating `mat` in **90-degree increments** (clockwise), otherwise return **false**.

---

## 📌 Examples

### Example 1

Input

```
mat = [[0,1],
       [1,0]]

target = [[1,0],
          [0,1]]
```

Output

```
true
```

Explanation  
By rotating the matrix by 90 degrees, we can obtain the target matrix.

---

### Example 2

Input

```
mat = [[0,1],
       [1,1]]

target = [[1,0],
          [0,1]]
```

Output

```
false
```

---

## 💡 Intuition

A matrix rotation by **90 degrees clockwise** can be done in two steps:

1. **Transpose the matrix** (swap rows and columns)
2. **Reverse each row**

Instead of manually checking all possible rotations, we simply:

- Rotate the matrix up to **4 times**
- After each rotation, check if it matches the target

If any rotation matches, return **true**

---

## ⚙️ Algorithm

1. Define a function to rotate the matrix:
   - Transpose the matrix
   - Reverse each row
2. Repeat up to 4 times:
   - Check if current matrix equals target
   - Rotate the matrix
3. If no match is found, return false.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int k = 0; k < 4; k++) {
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n²)  
Each rotation and comparison takes O(n²).

**Space Complexity:** O(1)  
In-place operations are used.

---

## 🏷 Tags

- Matrix
- Simulation
- Arrays
- Implementation
```