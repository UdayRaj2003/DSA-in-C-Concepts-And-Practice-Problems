 # 🧩 2833. Furthest Point From Origin

**Difficulty:** Easy  
**LeetCode Link:** https://leetcode.com/problems/furthest-point-from-origin/

---

## 🧠 Problem Statement

You are given a string `moves` of length `n` consisting only of:

- `'L'` → move left
- `'R'` → move right
- `'_'` → can be either left or right

You start from the origin `0` on a number line.

In each move:

- `'L'` decreases position by `1`
- `'R'` increases position by `1`
- `'_'` can be chosen as either left or right

Return the **furthest possible distance from the origin** after all moves.

---

## 📌 Examples

### Example 1

Input

``` id="ut02kl"
moves = "L_RL__R"
```

Output

``` id="9zj5lv"
3
```

Explanation

Choose all `'_'` moves in the direction that maximizes distance.

---

### Example 2

Input

``` id="zvw2vd"
moves = "_R__LL_"
```

Output

``` id="1r9twg"
5
```

---

## 💡 Intuition

To maximize distance from origin:

- If there are already more `'L'` moves, convert all `'_'` into `'L'`
- If there are more `'R'` moves, convert all `'_'` into `'R'`

Why?

Because adding all blanks to the stronger side increases displacement the most.

So:

``` id="kvp6r8"
Answer = |left - right| + blank
```

---

## ⚙️ Algorithm

1. Count:
   - Number of `'L'`
   - Number of `'R'`
   - Number of `'_'`

2. Compute:

``` id="4q1crs"
abs(left - right) + blank
```

3. Return result

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for (char ch : moves) {
            if (ch == 'L') left++;
            else if (ch == 'R') right++;
            else blank++;
        }
 
        return abs(left - right) + blank;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n)  
Single traversal of the string.

**Space Complexity:** O(1)  
Only constant extra space used.

---

## 🏷 Tags

- Strings
- Greedy
- Math
- Simulation