# 🧩 1009. Complement of Base 10 Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **Problem Link:** https://leetcode.com/problems/complement-of-base-10-integer/

---

# 🧠 Problem Statement

The **complement of an integer** is obtained by flipping all the `0`s to `1`s and all the `1`s to `0`s in its binary representation.

Given an integer `n`, return its **bitwise complement**.

---

# 📌 Examples

### Example 1

Input

```
n = 5
```

Output

```
2
```

Explanation

```
5  → 101
flip → 010 → 2
```

---

### Example 2

Input

```
n = 7
```

Output

```
0
```

Explanation

```
7 → 111
flip → 000 → 0
```

---

### Example 3

Input

```
n = 10
```

Output

```
5
```

Explanation

```
10 → 1010
flip → 0101 → 5
```

---

# 💡 Intuition

We only need to flip the **significant bits** of the number.

For example:

```
n = 5
binary = 101
```

If we create a mask with all bits `1` of the same length:

```
mask = 111
```

Then:

```
mask XOR n
```

```
111 XOR 101 = 010
```

Result = **2**

---

# ⚙️ Algorithm

1. If `n == 0`, return `1`.
2. Create a mask containing only `1`s with the same number of bits as `n`.
3. XOR the mask with `n`.
4. Return the result.

---

# 💻 C++ Solution

```cpp
class Solution {
public:
    int bitwiseComplement(int n) {

        if(n == 0) return 1;

        int mask = 0;
        int temp = n;

        while(temp){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }

        return mask ^ n;
    }
};
```

---

# ⏱ Complexity

| Type             | Complexity |
| ---------------- | ---------- |
| Time Complexity  | O(log n)   |
| Space Complexity | O(1)       |

---

# 🏷 Topics

* Bit Manipulation
* Math
