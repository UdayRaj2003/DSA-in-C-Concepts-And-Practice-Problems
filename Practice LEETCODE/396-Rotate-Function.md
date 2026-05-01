# 🧩 396. Rotate Function

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/rotate-function/

---

## 🧠 Problem Statement

You are given an integer array `nums` of length `n`.

Let `arr_k` be the array obtained after rotating `nums` clockwise by `k` positions.

Define the rotation function:

```
F(k) = 0 * arr_k[0] + 1 * arr_k[1] + ... + (n - 1) * arr_k[n - 1]
```

Return the **maximum value of F(k)** for all `k` from `0` to `n-1`.

---

## 📌 Examples

### Example 1

Input

```
nums = [4,3,2,6]
```

Output

```
26
```

Explanation

```
F(0) = 0*4 + 1*3 + 2*2 + 3*6 = 25
F(1) = 0*6 + 1*4 + 2*3 + 3*2 = 16
F(2) = 0*2 + 1*6 + 2*4 + 3*3 = 23
F(3) = 0*3 + 1*2 + 2*6 + 3*4 = 26
```

Maximum = 26

---

## 💡 Intuition

Brute force would compute each rotation independently → O(n²)

But we observe a pattern:

```
F(k) = F(k-1) + sum - n * nums[n-k]
```

Where:
- `sum` = sum of all elements

This allows us to compute each new rotation in **O(1)** time.

---

## ⚙️ Algorithm

1. Compute:
   - `sum` of array
   - Initial value `F(0)`
2. For each rotation `k` from `1` to `n-1`:
   - Use formula:

```
F(k) = F(k-1) + sum - n * nums[n-k]
```

3. Track maximum value
4. Return result

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, F = 0; 
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        long ans = F; 
        for(int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            ans = max(ans, F);
        }

        return ans;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n)  
Single traversal + recurrence updates.

**Space Complexity:** O(1)

---

## 🏷 Tags

- Arrays
- Math
- Greedy
- Dynamic Programming
- Prefix Sum
```