/***
// Given a set of strings, find the minimum cost to concat all of them.
// Cost of concatenating 2 strings is the sum of their lengths.
// E.g:
// { "abc", "bc", "bcde" }: "abc" + "bc" -> "abcbc" (5), then "abcbc" + "bcde" -> "abcbcbcde" (9)
// => TOTAL COST: 5 + 9 = 14
***/
// Create a Min Heap of the set of strings
// While heap is not empty, extract 2 items from heap and add them to the cost
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    static int const DEFAULT_CAPACITY = 20;
    int size;
    int capacity;
    vector<int> items;
    bool isLeaf(int index) { return index > (size - 2) / 2; }
    int getLeftIndex(int index) { return index * 2 + 1; }
    int getRightIndex(int index) { return index * 2 + 2; }
    int getParentIndex(int index) { return (index > size) ? index / 2 : 0; }
    void heapify();
    void rebuildHeap(int parentIndex);
public:
    MinHeap(): size(0), capacity(DEFAULT_CAPACITY) {}
    MinHeap(const vector<int>& arr);
    void add(const int item);
    int extract();
}

//----------
// Helpers
//----------
// Pre: everything is a subheap instead possible the one at parentIndex
void MinHeap::rebuildHeap(int parentIndex)
{
    while (!isLeaf(parentIndex)) {
        int smallerChild = getLeftIndex(parentIndex);
        int r = getRightIndex(parentIndex);
        if (r < size) {
            if (items[r] < items[smallerChild]) smallerChild = r;
        }
        if (items[parentIndex] <items[smallerChild]) {
            swap(items[parentIndex], items[smallerChild]);
            parentIndex = smallerChild;
        }
    }
}
// Pre condition: items is not empty
// Post condition: items now represents a min heap
void MinHeap::heapify()
{
    for (int i = (size - 1) / 2; i >= 0; i--) {
        rebuildHeap(i);
    }
}

MinHeap::MinHeap(const vector<int>& arr)
{
    items = arr;
    heapify();
}

int main()
{
    vector<int> s_arrs = { }
}