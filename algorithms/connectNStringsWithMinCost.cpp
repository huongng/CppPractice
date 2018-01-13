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
#include <string>
using namespace std;

class MinHeap
{
private:
    static int const DEFAULT_CAPACITY = 20;
    int size;
    int capacity;
    vector<string> items;
    bool isLeaf(int index) {
        if (size == 1) return true;
        return index > (size - 2) / 2; }
    int getLeftIndex(int index) { return index * 2 + 1; }
    int getRightIndex(int index) { return index * 2 + 2; }
    int getParentIndex(int index) { return (index > size) ? index / 2 : 0; }
    void heapify();
    void rebuildHeap(int parentIndex);
public:
    MinHeap(): size(0), capacity(DEFAULT_CAPACITY) {}
    MinHeap(const vector<string>& arr);
    void add(const string item);
    int getSize() { return size; }
    string peekTop() const { return items[0]; }
    string extract();
};
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
            if (items[r].length() < items[smallerChild].length()) smallerChild = r;
        }
        if (items[parentIndex].length() > items[smallerChild].length()) {
            swap(items[parentIndex], items[smallerChild]);
        }
        parentIndex = smallerChild;
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

MinHeap::MinHeap(const vector<string>& arr)
{
    items = arr;
    size = items.size();
    capacity = size * 2;
    heapify();
}

string MinHeap::extract()
{
    if (size == 0) return "";
    string item = items[0];
    swap(items[0], items[size - 1]);
    size--;
    rebuildHeap(0);
    return item;
}

void MinHeap::add(const string item)
{
    int index = size;
    items[index] = item;
    size++;
    bool inPlace = false;
    while (!inPlace && index > 0) {
        int parentIndex = getParentIndex(index);
        if (items[parentIndex].length() > items[index].length()) {
            swap(items[parentIndex], items[index]);
            index = parentIndex;
        }
        else {
            inPlace = true;
        }
    }
}

int minCost(MinHeap& heap)
{
    int cost = 0;
    while (heap.getSize() > 1) {
        string str1 = heap.extract();
        string str2 = heap.extract();
        cost += str1.length() + str2.length();
        heap.add(str1+str2);
    }
    return cost;
}
int main()
{
    vector<string> s_arrs = { "abc", "cd", "cded", "thjfkk", "a"};
    MinHeap heap(s_arrs);
    cout << minCost(heap) << endl;
    return 0;
}
