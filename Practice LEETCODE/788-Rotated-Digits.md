# 🧩 788. Rotated Digits

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/rotated-digits/

---

## 🧠 Problem Statement

An integer is called a **good number** if after rotating each digit individually
by 180 degrees, the resulting number is **valid and different** from the original.

Digit mapping:

- 0 → 0  
- 1 → 1  
- 8 → 8  
- 2 ↔ 5  
- 6 ↔ 9  
- 3, 4, 7 → invalid  

Given an integer `n`, return how many numbers in range `[1, n]` are good.

---

## 📌 Examples

### Example 1

Input

```
n = 10
```

Output

```
4
```

Explanation

Good numbers are:  
```
2, 5, 6, 9
```

---

## 💡 Intuition

We classify digits into 3 types:

1. **Invalid digits** → {3, 4, 7}
2. **Valid but unchanged** → {0, 1, 8}
3. **Valid and changed** → {2, 5, 6, 9}

A number is good if:
- It contains **no invalid digits**
- It contains **at least one changed digit**

---

## ⚙️ Algorithm

1. Initialize count = 0
2. For each number from 1 to n:
   - Extract digits one by one
   - If digit is invalid → skip
   - If digit is changing → mark changed = true
3. If valid and changed → increment count
4. Return count

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;

        for(int i = 1; i <= n; i++) {
            int num = i;
            bool valid = true;
            bool changed = false;

            while(num > 0) {
                int d = num % 10;

                if(d == 3 || d == 4 || d == 7) {
                    valid = false;
                    break;
                }
                if(d == 2 || d == 5 || d == 6 || d == 9) {
                    changed = true;
                }

                num /= 10;
            }

            if(valid && changed) count++;
        }

        return count;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n × d)  
Where `d` is number of digits.

**Space Complexity:** O(1)

---

## 🏷 Tags

- Math
- Simulation
- Digit Manipulation
```