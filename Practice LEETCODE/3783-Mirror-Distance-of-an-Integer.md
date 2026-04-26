# 🧩 3783. Mirror Distance of an Integer

**Difficulty:** Easy  
**LeetCode Link:** https://leetcode.com/problems/mirror-distance-of-an-integer/

---

## 🧠 Problem Statement

You are given an integer `n`.

Define its **mirror distance** as:

```text
abs(n - reverse(n))
```

Where:

- `reverse(n)` is the integer formed by reversing the digits of `n`
- `abs(x)` denotes the absolute value of `x`

Return the mirror distance of `n`.

---

## 📌 Examples

### Example 1

Input

```text
n = 25
```

Output

```text
27
```

Explanation

```text
reverse(25) = 52
abs(25 - 52) = 27
```

---

### Example 2

Input

```text
n = 120
```

Output

```text
99
```

Explanation

```text
reverse(120) = 21
abs(120 - 21) = 99
```

---

## 💡 Intuition

To calculate mirror distance:

1. Reverse the digits of the number
2. Find the absolute difference between the original and reversed value

The reversal is done using:

- `% 10` → get last digit
- `/ 10` → remove last digit

This is a standard digit manipulation problem.

---

## ⚙️ Algorithm

1. Initialize `rev = 0`
2. While `n > 0`:
   - Extract last digit using `% 10`
   - Add it to reversed number
   - Remove last digit using `/ 10`
3. Return:

```text
abs(original_number - reversed_number)
```

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int reverseNumber(int n) {
        int rev = 0;
        
        while (n > 0) {
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        
        return rev;
    }

    int mirrorDistance(int n) {
        int rev = reverseNumber(n);
        return abs(n - rev);
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(d)  
Where `d` is the number of digits in `n`

**Space Complexity:** O(1)

---

## 🏷 Tags

- Math
- Number Manipulation
- Simulation
- Easy Problem