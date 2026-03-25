# 🧩 207. Course Schedule

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/course-schedule/

---

## 🧠 Problem Statement

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`.

You are given an array `prerequisites` where:

```
prerequisites[i] = [a, b]
```

indicates that to take course `a`, you must first complete course `b`.

Return **true** if you can finish all courses, otherwise return **false**.

---

## 📌 Examples

### Example 1

Input

```
numCourses = 2
prerequisites = [[1,0]]
```

Output

```
true
```

Explanation  
You can take course `0` first, then course `1`.

---

### Example 2

Input

```
numCourses = 2
prerequisites = [[1,0],[0,1]]
```

Output

```
false
```

Explanation  
There is a cycle between courses `0` and `1`.

---

## 💡 Intuition

This problem can be modeled as a **directed graph** where:

- Nodes represent courses
- Edges represent prerequisites

We need to check if the graph contains a **cycle**.

Using **Kahn’s Algorithm (BFS)**:
- Start with nodes having **indegree = 0**
- Process them and reduce indegree of neighbors
- Continue until no nodes are left

If we process all nodes → no cycle → return true  
Otherwise → cycle exists → return false

---

## ⚙️ Algorithm

1. Build adjacency list from prerequisites.
2. Compute indegree of each node.
3. Push all nodes with indegree `0` into a queue.
4. While queue is not empty:
   - Pop node
   - Increment processed count
   - Reduce indegree of neighbors
   - Push neighbors with indegree `0`
5. If processed count equals total nodes:
   - Return true
6. Else:
   - Return false

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    bool canFinish(int t, vector<vector<int>>& p) {
        vector<vector<int>> adj(t);
        vector<int> in(t, 0);
        for (auto i : p) {
            in[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }

        queue<int> q;
        for (int i = 0; i < t; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }
        int c = 0;
        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            cout << "Node :" << front << endl;
            c++;
            for (auto nbr : adj[front]) {
                in[nbr]--;
                if (!in[nbr]) {
                    q.push(nbr);
                }
            }
        }
        cout << c << endl;
        if (c == t) {
            return true;
        }
        return false;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(V + E)  
Each node and edge is processed once.

**Space Complexity:** O(V + E)  
Adjacency list and queue are used.

---

## 🏷 Tags

- Graph
- BFS
- Topological Sort
- Directed Graph
- Cycle Detection
```