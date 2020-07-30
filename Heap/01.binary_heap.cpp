/*
    A Binary Heap is a Binary Tree with the following properties:
        1.  It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible).
        2.  A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must be minimum among all 
            keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int *arr;
    int capacity, heap_size;

    int parent(int i) { return (i - 1) / 2; }

    int left(int i) { return (2 * i + 1); }

    int right(int i) { return (2 * i + 2); }

    void MinHeapify(int i);

public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    ~MinHeap()
    {
        delete[] arr;
    }

    int getMin() { return arr[0]; }

    void insertKey(int key);

    void decreaseKey(int i, int new_val);

    int extractMin();

    void deleteKey(int i);
};

// Insert a new key
void MinHeap::insertKey(int key)
{
    if (heap_size == capacity)
    {
        cout << "Overflow, could not insert key";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    arr[i] = key;

    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void MinHeap::decreaseKey(int i, int new_val)
{
    if (arr[i] <= new_val)
    {
        cout << "Could not decrease key\n";
        return;
    }

    arr[i] = new_val;
    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap 
int MinHeap::extractMin() 
{
    if (heap_size <= 0) 
        return INT_MAX; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return arr[0]; 
    } 
  
    // Store the minimum value, and remove it from heap 
    int root = arr[0]; 
    arr[0] = arr[heap_size-1]; 
    heap_size--; 
    MinHeapify(0); 
  
    return root; 
}

// This function deletes key at index i. 
void MinHeap::deleteKey(int i) 
{ 
    decreaseKey(i, INT_MIN); 
    extractMin(); 
}

// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void MinHeap::MinHeapify(int i) 
{ 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && arr[l] < arr[i]) 
        smallest = l; 
    if (r < heap_size && arr[r] < arr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(arr[i], arr[smallest]); 
        MinHeapify(smallest); 
    } 
}

int main()
{
    MinHeap h(11); 
    h.insertKey(3);
    cout << "3 inserted\n";

    h.insertKey(2); 
    cout << "2 inserted\n"; 

    h.deleteKey(1); 
    cout << "Key at index 1 deleted\n";

    h.insertKey(15);
    cout << "15 inserted\n"; 

    h.insertKey(5); 
    cout << "5 inserted\n"; 

    h.insertKey(4);
    cout << "4 inserted\n"; 

    h.insertKey(45); 
    cout << "45 inserted\n"; 

    cout << "Deleting min key : " << h.extractMin() << endl; 

    cout << "Min key is: " << h.getMin() << endl;

    h.decreaseKey(2, 1); 
    cout << "Decreased index 2 with 1\n"; 

    cout << "Min key is: " << h.getMin() << endl; 
    return 0;
}