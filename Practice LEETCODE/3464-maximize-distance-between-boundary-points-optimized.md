# 🧩 Maximize Distance Between Selected Boundary Points (Optimized)

**Difficulty:** Hard  
**LeetCode Link:** <problem link>

---

## 🧠 Problem Statement

You are given:

- A square of side length `s`
- A list of points located only on the boundary of the square
- An integer `k`

Your task is to select exactly `k` points such that the **minimum Manhattan distance**
between consecutive selected points is maximized.

Return the maximum possible value of this minimum distance.

---

## 📌 Examples

### Example 1

Input

```text
s = 4
points = [[0,0],[4,0],[4,4],[0,4]]
k = 2
```

Output

```text
8
```

Explanation

Choosing opposite corners gives the maximum Manhattan distance.

---

## 💡 Intuition

Since all points lie on the square boundary, we can map every point to a single
position on the square’s perimeter.

This converts the problem into:

> Select `k` points on a circular line while maximizing the minimum distance.

Then:

- Use **Binary Search** on the answer
- For each candidate distance:
  - Precompute the next valid reachable point
  - Greedily jump through points to verify feasibility

This avoids expensive pairwise checking.

---

## ⚙️ Algorithm

### Step 1: Convert to Perimeter Distance

Map each boundary point into a 1D perimeter value.

### Step 2: Sort Positions

Sort all perimeter distances.

### Step 3: Binary Search on Answer

Search for the maximum minimum distance.

### Step 4: Feasibility Check

For each candidate distance `x`:

- Precompute `nxt[i]`:
  the next point at least `x` away

- Try greedily selecting `k` points

- Verify circular wrap-around constraint

If valid → increase answer  
Else → decrease answer

---

## 💻 Solution (C++)

```cpp
uint32_t dists[15000];
uint16_t nxt[15000];

class Solution {
public:
    int maxDistance(int s, vector<vector<int>>& points, int k) {
        const uint64_t n = points.size(), perim = 4UL * s;

        for (uint i = 0; i < n; i++) {
            uint64_t x = points[i][0], y = points[i][1];
            dists[i] = (x == 0 || y == s) ? perim - x - y : x + y;
        }

        sort(dists, dists + n);

        const auto check = [&](uint64_t x) -> bool {
            for (uint i = 0, r = 0; i < n; i++) {
                r = max(r, i + 1);
                while (r < n && dists[r] < dists[i] + x) r++;
                nxt[i] = r;
            }
            uint64_t maxreach = dists[n - 1] + perim - (k - 1) * x;
            auto limit = perim - x;

            for (uint i = 0; i < n && dists[i] <= maxreach; i++) {
                uint j = i;
                for (uint r = k - 1; r > 0 && j != n; r--) {
                    j = nxt[j];
                }
                if (j != n && dists[j] - dists[i] <= limit) return true;
            }
            return false;
        };

        uint64_t lo = 1, hi = perim / k;
        while (lo < hi) {
            auto x = (lo + hi + 1) / 2;
            if (check(x))
                lo = x;
            else
                hi = x - 1;
        }
        return hi;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n log n + n log(answer))

- Sorting → O(n log n)
- Binary Search → O(log(answer))
- Each check → O(n)

**Space Complexity:** O(n)

---

## 🏷 Tags

- Binary Search
- Greedy
- Geometry
- Optimization
- Hard Problem
- Circular Traversal