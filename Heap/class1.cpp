#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int *arr;
    int size;
    int capacity;

    heap(int capacity)
    {
        this->capacity = capacity;
        this->arr = new int[capacity + 1]; // 1-based indexing
        this->size = 0;
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = value;

        // Heapify up (percolate up)
        while (index > 1)
        {
            int parent_index = index / 2;
            if (arr[parent_index] < arr[index])
            {
                swap(arr[parent_index], arr[index]);
                index = parent_index;
            }
            else
            {
                break;
            }
        }
    }

    void printheap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int deleteheap()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return -1; // Indicating empty heap
        }

        int answer = arr[1]; // Root element
        arr[1] = arr[size];  // Move last element to root
        size--;

        // Heapify down (percolate down)
        int index = 1;
        while (index <= size)
        {
            int leftindex = 2 * index;
            int rightindex = 2 * index + 1;
            int largestindex = index;

            if (leftindex <= size && arr[leftindex] > arr[largestindex])
            {
                largestindex = leftindex;
            }
            if (rightindex <= size && arr[rightindex] > arr[largestindex])
            {
                largestindex = rightindex;
            }
            if (largestindex != index)
            {
                swap(arr[index], arr[largestindex]);
                index = largestindex;
            }
            else
            {
                break;
            }
        }
        return answer;
    }
};

// Heapify function for converting an array to a heap (1-based indexing)
void heapify(int size, int *arr, int index)
{
    while (index <= size)
    {
        int leftindex = 2 * index;
        int rightindex = 2 * index + 1;
        int largestindex = index;

        if (leftindex <= size && arr[leftindex] > arr[largestindex])
        {
            largestindex = leftindex;
        }
        if (rightindex <= size && arr[rightindex] > arr[largestindex])
        {
            largestindex = rightindex;
        }
        if (largestindex != index)
        {
            swap(arr[index], arr[largestindex]);
            index = largestindex;
        }
        else
        {
            break;
        }
    }
}

// Convert an array into a heap (1-based indexing)
void arrtoheap(int *arr, int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        heapify(size, arr, i);
    }
}
void heapsort(int *arr, int size)
{
    while (size != 1)
    {
        swap(arr[1], arr[size]);
        size--;
        heapify(size, arr, 1);
    }
}
int main()
{
    heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(25);
    h.insert(5);
    h.insert(40);
    h.insert(35);
    h.insert(45);
    h.insert(50);

    cout << "Heap after insertions: ";
    h.printheap();

    h.deleteheap();
    cout << "Heap after deletion: ";
    h.printheap();

    // Array representation of a heap (1-based indexing)
    int arr[] = {-1, 3, 5, 2, 6, 8, 20, 10, 12, 18, 9}; // -1 at index 0 (unused)
    int size = 10;

    arrtoheap(arr, size); // Convert array to heap

    cout << "Heapified array: ";
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, size);
    cout << "printing heap: " << endl;
    for (int i = 1; i <= size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
