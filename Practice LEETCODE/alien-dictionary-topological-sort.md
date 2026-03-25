# 🧩 Alien Dictionary

**Difficulty:** Hard  
**LeetCode Link:** https://leetcode.com/problems/alien-dictionary/

---

## 🧠 Problem Statement

Given a sorted list of words from an **alien language**, determine the **order of characters** in that language.

Rules:

- Words are sorted lexicographically based on unknown character order
- You must return a string representing the correct order of characters
- If no valid ordering exists, return an empty string

---

## 📌 Examples

### Example 1

Input

```
words = ["wrt","wrf","er","ett","rftt"]
```

Output

```
"wertf"
```

---

### Example 2

Input

```
words = ["z","x"]
```

Output

```
"zx"
```

---

### Example 3

Input

```
words = ["z","x","z"]
```

Output

```
""
```

Explanation  
There is a cycle, so no valid ordering exists.

---

## 💡 Intuition

We treat characters as nodes in a **directed graph**.

By comparing adjacent words:
- Find the **first different character**
- This gives us a dependency (edge)

Example:
```
"abc" → "abd"
c → d
```

Then we perform **topological sorting** to find a valid order.

If:
- We process all nodes → valid order exists
- Otherwise → cycle → return ""

---

## ⚙️ Algorithm

1. Initialize:
   - Adjacency list
   - Indegree map

2. Add all unique characters to indegree map

3. Compare adjacent words:
   - Find first differing character
   - Add edge and update indegree
   - Handle invalid prefix case

4. Apply **Kahn’s Algorithm**:
   - Push nodes with indegree 0 into queue
   - Process nodes and reduce indegree
   - Build result string

5. If result size equals number of characters:
   - Return result
6. Else:
   - Return empty string

---

## 💻 Solution (C++)

```cpp
class Solution {
public:

    string topoSort(unordered_map<char, vector<char>>& adj,
                    unordered_map<char, int>& in) {

        queue<char> q;
        string order = "";
 
        for (auto &i : in) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }

        while (!q.empty()) {
            char front = q.front();
            q.pop();

            order += front;

            for (auto nbr : adj[front]) {
                in[nbr]--;
                if (in[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
 
        if (order.size() == in.size()) return order;

        return "";
    }

    string findOrder(vector<string> &w) {

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> in;
 
        for (auto &word : w) {
            for (char c : word) {
                in[c] = 0;
            }
        }
 
        for (int i = 0; i < w.size() - 1; i++) {
            string s1 = w[i];
            string s2 = w[i + 1];

            int len = min(s1.size(), s2.size());
            int j = 0;

            while (j < len && s1[j] == s2[j]) {
                j++;
            }
 
            if (j == len && s1.size() > s2.size()) {
                return "";
            }

            if (j < len) {
                adj[s1[j]].push_back(s2[j]);
                in[s2[j]]++;
            }
        }

        return topoSort(adj, in);
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(C + E)  
C = number of unique characters, E = number of edges

**Space Complexity:** O(C + E)  
For adjacency list and indegree map

---

## 🏷 Tags

- Graph
- Topological Sort
- BFS
- Directed Graph
- String Processing
- Kahn’s Algorithm
```