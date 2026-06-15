# 🧩 2095. Delete the Middle Node of a Linked List

**Difficulty:** Medium  
**LeetCode Link:** https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

---

## 🧠 Problem Statement

You are given the head of a singly linked list.

Delete the middle node and return the head of the modified linked list.

The middle node of a linked list of size `n` is the `⌊n / 2⌋`th node (0-indexed).

---

## 📌 Examples

### Example 1

Input

```
head = [1,3,4,7,1,2,6]
```

Output

```
[1,3,4,1,2,6]
```

Explanation

The middle node is `7`, so it is removed.

---

### Example 2

Input

```
head = [1,2,3,4]
```

Output

```
[1,2,4]
```

Explanation

The middle node is `3`.

---

### Example 3

Input

```
head = [2]
```

Output

```
[]
```

Explanation

The only node is removed.

---

## 💡 Intuition

To delete the middle node:

1. Count the total number of nodes.
2. Compute the middle index using:

```text
middle = length / 2
```

3. Traverse to the node just before the middle.
4. Update pointers to skip the middle node.

This removes the middle node without using extra space.

---

## ⚙️ Algorithm

1. Traverse the linked list and calculate its length.
2. If length is 1:
   - Return `NULL`.
3. Compute:
   ```
   middle = length / 2
   ```
4. Traverse to the node before the middle.
5. Remove the middle node by updating pointers.
6. Return head.

---

## 💻 Solution (C++)

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if(len==1){
            return NULL;
        }
        int half = len / 2;
        temp = head;
        while (half - 1>0) {
            temp = temp->next;
            half--;
        }

        ListNode* net = temp->next->next;
        ListNode* curr = temp->next;
        temp->next = NULL;
        curr->next = NULL;
        temp->next = net;
        return head;
    }
};
```

---

## ⏱ Complexity

**Time Complexity:** O(n)

- One traversal to calculate length
- One traversal to reach the middle

**Space Complexity:** O(1)

---

## 🏷 Tags

- Linked List
- Two Pass Traversal
- Pointer Manipulation
- Data Structures