# 🧩 Minimum Distance Between Mirror Pairs

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/

---

## 🧠 Problem Statement

You are given an integer array `nums`.

A **mirror pair** is a pair of indices `(i, j)` such that:

- `0 ≤ i < j < nums.length`
- `reverse(nums[i]) == nums[j]`

Return the **minimum distance** `(j - i)` among all mirror pairs.

If no such pair exists, return `-1`.

---

## 📌 Examples

### Example 1

Input

```
nums = [123,321,456,654]
``` id="n1q2pr"

Output

```
1
``` id="z7d3wt"

Explanation  
Mirror pairs:
- (0,1) → 123 ↔ 321 → distance = 1
- (2,3) → 456 ↔ 654 → distance = 1

Minimum = 1

---

### Example 2

Input

```
nums = [10,1,100]
``` id="xk9q2s"

Output

```
-1
``` id="b2n8zd"

Explanation  
No valid mirror pairs exist.

---

## 💡 Intuition

Instead of checking all pairs (O(n²)), we use a **hashmap**.

Key idea:
- Store the **reverse of each number** along with its index
- While iterating, check if the current number exists in the map
- If yes → mirror pair found

This reduces complexity to **O(n)**.

---

## ⚙️ Algorithm

1. Initialize a hashmap `mp`
2. Initialize `ans = ∞`
3. Traverse the array:
   - If current number exists in map:
     - Update minimum distance
   - Compute reverse of current number
   - Store reverse in map with current index
4. If no pair found → return -1
5. Else return minimum distance

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;  
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
             
            if (mp.find(nums[i]) != mp.end()) {
                ans = min(ans, i - mp[nums[i]]);
            }
 
            int rev = reverseNum(nums[i]);
            mp[rev] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n × d)  
Where `d` is number of digits in each number.

**Space Complexity:** O(n)  
For hashmap storage.

---

## 🏷 Tags

- Arrays
- HashMap
- Math
- Simulation
```