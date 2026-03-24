# 🧩 2360. Longest Cycle in a Graph

**Difficulty:** Hard  
**LeetCode Link:** https://leetcode.com/problems/longest-cycle-in-a-graph/

---

## 🧠 Problem Statement

You are given a **directed graph** of `n` nodes numbered from `0` to `n - 1`.

Each node has **at most one outgoing edge**.  
The graph is represented by an array `edges` where:

- `edges[i] = j` means there is a directed edge from node `i` to node `j`
- `edges[i] = -1` means node `i` has no outgoing edge

Return the **length of the longest cycle** in the graph.  
If no cycle exists, return `-1`.

---

## 📌 Examples

### Example 1

Input

```
edges = [3,3,4,2,3]
```

Output

```
3
```

Explanation  
The cycle is: `2 → 4 → 3 → 2`

---

### Example 2

Input

```
edges = [2,-1,3,1]
```

Output

```
-1
```

Explanation  
There is no cycle in the graph.

---

## 💡 Intuition

Each node has **only one outgoing edge**, so the graph behaves like multiple chains that may form cycles.

We use a **visit time approach**:
- Assign a timestamp when visiting nodes
- Track the start time of each traversal

If we revisit a node within the same traversal, we have detected a cycle.

Cycle length =  
```
current_time - visit_time[node]
```

---

## ⚙️ Algorithm

1. Initialize:
   - `vis` array to store visit time
   - `time = 1`
   - `ans = -1`

2. Loop through each node:
   - Skip if already visited

3. Start traversal:
   - Store `startTime`
   - Follow edges until:
     - Node becomes `-1` OR
     - Node is already visited

4. If a visited node is found:
   - Check if it belongs to current traversal (`vis[node] >= startTime`)
   - Compute cycle length

5. Update maximum cycle length

6. Return result

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        int time = 1;
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;

            int node = i;
            int startTime = time;

            while (node != -1 && !vis[node]) {
                vis[node] = time++;
                node = edges[node];
            }
 
            if (node != -1 && vis[node] >= startTime) {
                ans = max(ans, time - vis[node]);
            }
        }

        return ans;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n)  
Each node is visited at most once.

**Space Complexity:** O(n)  
For storing visit times.

---

## 🏷 Tags

- Graph
- DFS
- Cycle Detection
- Directed Graph
- Arrays
- Topological Insight
```