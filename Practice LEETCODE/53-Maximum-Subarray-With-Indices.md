# 🧩 53. Maximum Subarray (With Subarray Tracking)

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/maximum-subarray/

---

## 🧠 Problem Statement

Given an integer array `nums`, find the **contiguous subarray** with the **maximum sum** and also print the subarray.

Return the maximum sum.

---

## 📌 Examples

### Example 1

Input

```
nums = [-2,1,-3,4,-1,2,1,-5,4]
```

Output

```
Max Sum = 6
Subarray = [4,-1,2,1]
```

---

### Example 2

Input

```
nums = [5,4,-1,7,8]
```

Output

```
Max Sum = 23
Subarray = [5,4,-1,7,8]
```

---

## 💡 Intuition

This is an extension of **Kadane’s Algorithm**.

Key ideas:
- Keep track of running sum
- Reset when sum becomes negative
- Track starting index when sum becomes 0
- Update answer and indices when a better sum is found

This allows us to find both:
- Maximum sum
- Actual subarray

---

## ⚙️ Algorithm

1. Initialize:
   - `sum = 0`
   - `maxi = -∞`
   - `start`, `end`, `tempStart`

2. Traverse array:
   - If `sum == 0`, update `tempStart`
   - Add current element to `sum`
   - If `sum > maxi`:
     - Update `maxi`
     - Update `start` and `end`
   - If `sum < 0`, reset `sum = 0`

3. Print subarray from `start` to `end`

4. Return `maxi`

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        int start = 0, end = 0;
        int tempStart = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (sum == 0) {
                tempStart = i;
            }

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                start = tempStart;
                end = i;
            }

            if (sum < 0) {
                sum = 0;
            }
        }
        cout << "Subarray: ";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
        return maxi;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n)  
Single pass through the array.

**Space Complexity:** O(1)  
Only variables used.

---

## 🏷 Tags

- Arrays
- Greedy
- Dynamic Programming
- Kadane’s Algorithm
- Subarray
```