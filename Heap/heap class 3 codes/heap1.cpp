#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Info {
public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int a, int b, int c) {
        this->data = a;
        this->rowIndex = b;
        this->colIndex = c;
    }
};

class compare {
public:
    bool operator()(Info* a, Info* b) {
        return a->data > b->data;  // Min-heap
    } 
};

void mergeKSortedArrays(vector<vector<int>> &arr, vector<int> &ans) {
    priority_queue<Info*, vector<Info*>, compare> pq;

    int k = arr.size();  // Number of rows

    // Step 1: Insert first elements of each row into the priority queue
    for (int row = 0; row < k; row++) {
        if (!arr[row].empty()) {  // Ensure the row is not empty
            Info* temp = new Info(arr[row][0], row, 0);
            pq.push(temp);
        }
    }

    // Step 2: Process elements from priority queue
    while (!pq.empty()) {
        Info* temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;

        // Store the popped element in the answer vector
        ans.push_back(topData);

        // Insert the next element from the same row into the priority queue
        if (topCol + 1 < arr[topRow].size()) {  // Ensure within column bounds
            Info* newInfo = new Info(arr[topRow][topCol + 1], topRow, topCol + 1);
            pq.push(newInfo);
        }

        delete temp;  // Free allocated memory
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 4, 8, 11},
        {2, 3, 6, 10},
        {5, 7, 12, 14}
    };

    vector<int> ans;
    mergeKSortedArrays(arr, ans);

    cout << "Printing merged sorted array: " << endl;
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
