# 🧩 1415. The k-th Lexicographical String of All Happy Strings of Length n

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

---

## 🧠 Problem Statement

A **happy string** is a string that:

- Consists only of characters from the set **['a', 'b', 'c']**
- No two **adjacent characters are the same**

For example:

```
"abc", "ac", "bca"
```

are happy strings, while:

```
"aa", "abb"
```

are not.

Given two integers **n** and **k**, consider all happy strings of length **n**
sorted in **lexicographical order**.

Return the **k-th string** in this sorted list.  
If there are fewer than **k** happy strings, return an **empty string**.

---

## 📌 Examples

### Example 1

Input

```
n = 1, k = 3
```

Output

```
"c"
```

Explanation

The happy strings of length 1 are:

```
["a","b","c"]
```

The **3rd** string is `"c"`.

---

### Example 2

Input

```
n = 1, k = 4
```

Output

```
""
```

Explanation

There are only **3 happy strings**, so the answer is an empty string.

---

### Example 3

Input

```
n = 3, k = 9
```

Output

```
"cab"
```

---

## 💡 Intuition

A happy string cannot have **two identical consecutive characters**.

We can generate all valid strings using **Depth First Search (DFS)** or
**backtracking**.

At each step:
- Try adding characters **'a', 'b', 'c'**
- Only add a character if it is **different from the last character**

Since we iterate characters in lexicographical order, the generated
strings will also be in lexicographical order.

We keep a **counter** and stop when we reach the **k-th valid string**.

---

## ⚙️ Algorithm

1. Initialize:
   - `count` to track the number of valid strings
   - `ans` to store the result

2. Start DFS with an empty string.

3. If the current string length equals **n**:
   - Increment the counter
   - If `count == k`, store the current string.

4. Otherwise:
   - Try appending characters `'a'`, `'b'`, `'c'`
   - Only append if it is **not equal to the last character**

5. Stop recursion early once the answer is found.

6. Return the stored answer.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    string ans = "";
    int count = 0;

    void dfs(string curr, int n, int k){
        if(curr.size() == n){
            count++;
            if(count == k) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}){
            if(curr.empty() || curr.back() != c){
                dfs(curr + c, n, k);
                if(!ans.empty()) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        dfs("", n, k);
        return ans;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(3 × 2^(n-1))  
Each position has at most **2 valid choices** after the first character.

**Space Complexity:** O(n)  
Recursion depth equals the length of the string.

---

## 🏷 Tags

- Backtracking
- Recursion
- Strings
- DFS
- Combinatorics