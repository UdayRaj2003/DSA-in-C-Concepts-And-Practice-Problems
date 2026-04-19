# 🧩 1855. Maximum Distance Between a Pair of Values

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/

---

## 🧠 Problem Statement

You are given two **non-increasing** 0-indexed integer arrays `nums1` and `nums2`.

A pair of indices `(i, j)` is valid if:

- `0 <= i < nums1.length`
- `0 <= j < nums2.length`
- `i <= j`
- `nums1[i] <= nums2[j]`

Return the **maximum distance** of any valid pair `(i, j)`.

The distance of the pair is:

``` id="0n8srf"
j - i
```

---

## 📌 Examples

### Example 1

Input

``` id="ik5ohw"
nums1 = [55,30,5,4,2]
nums2 = [100,20,10,10,5]
```

Output

``` id="w3f60m"
2
```

Explanation

The valid pair with maximum distance is:

``` id="khccnh"
(i, j) = (2, 4)
```

Distance:

``` id="wjj4rr"
4 - 2 = 2
```

---

### Example 2

Input

``` id="grl9ae"
nums1 = [2,2,2]
nums2 = [10,10,1]
```

Output

``` id="92l1vt"
1
```

---

## 💡 Intuition

Since both arrays are sorted in **non-increasing order**, we can use **Binary Search**.

For each index `i` in `nums1`:

- We need the farthest index `j` in `nums2`
- Such that:

``` id="eif7l3"
i <= j and nums1[i] <= nums2[j]
```

Instead of checking every `j`, binary search helps us find the **rightmost valid j efficiently**.

---

## ⚙️ Algorithm

1. For each index `i` in `nums1`:
   - Start binary search from `j = i`
   - Search in `nums2`

2. Find the farthest valid `j` such that:

``` id="j4gxaf"
nums1[i] <= nums2[j]
```

3. Compute:

``` id="j86wz1"
distance = j - i
```

4. Update maximum distance

5. Return final answer

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    
    int bs(int i, vector<int>& nums1, vector<int>& nums2) {
        int low = i, high = nums2.size() - 1;
        int ans = i;

        while (low <= high) {
            int mid = low + (high - low) / 2;
 
            if (nums1[i] <= nums2[mid]) {
                ans = mid;      
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans - i;  
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;

        for (int i = 0; i < nums1.size(); i++) {
            maxi = max(maxi, bs(i, nums1, nums2));
        }

        return maxi;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n log m)  
Where:
- `n = nums1.size()`
- `m = nums2.size()`

Each element of nums1 performs one binary search on nums2.

**Space Complexity:** O(1)

---

## 🏷 Tags

- Arrays
- Binary Search
- Two Pointers
- Greedy