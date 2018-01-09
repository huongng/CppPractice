/**
 * Sort elements by frequency in decreasing order
 * If 2 elements have the same frequency, sort by appearing order
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int id;
    int freq;
    int index;
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
    Node(int id, int freq, int index) : id(id), freq(freq), index(index),  left(nullptr), right(nullptr) {}
    //Node* operator=(Node*)
};

class BST
{
private:
    Node* root;
    int size;
    void insert(int data, int index, Node* node);
    void inorder(Node* node, vector<Node*>& tracks);
public:
    BST() : root(nullptr) {}
    void insert(int data, int index);
    void inorder(vector<Node*>& tracks);
    int getSize() { return size; }
};

void BST::insert(int data, int index)
{
    if (root == nullptr) {
        size++;
        root = new Node(data, 1, index);
        return;
    }
    insert(data, index, root);    
}
void BST::insert(int data, int index, Node* node)
{
    if (data == node->id) {
        //cout << "update: " << data << " with freq " << node->freq << endl;
        node->freq++;
        return;
    }
    if (data < node->id) {
        if (node->left != nullptr)
            insert(data, index, node->left);
        else {
            //cout << "insert left: " << data << endl;
            node->left = new Node(data, 1, index);
            size++;
        }
    }
    else if (data > node->id) {
        if (node->right != nullptr)
            insert(data, index, node->right);
        else {
            //cout << "insert right: " << data << endl;
            node->right = new Node(data, 1, index);
            size++;
        }
    }
}
void BST::inorder(vector<Node*>& tracks)
{
    if (root == nullptr) return;
    inorder(root, tracks);
}
void BST::inorder(Node* node, vector<Node*>& tracks)
{
    if (node == nullptr) return;
    inorder(node->left, tracks);
    tracks.push_back(node);
    inorder(node->right, tracks);
}

bool compare(Node* n1, Node* n2)
{
    if (n1->freq == n2->freq) return n1->index < n2->index;
    return n1->freq > n2->freq;
}

void sortByFrequency(vector<int>& arr)
{
    // build a BST from arr, with each tree node having structure {val, frequency, first index}
    BST tree;
    for (int i = 0; i < arr.size(); i++) {
        tree.insert(arr[i], i);
    }
    // Traverse inorder and put frequency in a 2-D array of (frequency, Node*)
    vector<Node*> tracks;
    tree.inorder(tracks);
    // sort vector based on frequency
    // if frequency is the same, sort by index
    sort(tracks.begin(), tracks.end(), compare);
    int i = 0;
    for (auto p = tracks.begin(); p != tracks.end(); p++) {
      int frequency = (*p)->freq;
      while (frequency--) {
        arr[i] = (*p)->id;
        i++;
      }
    }
}
int main()
{
    vector<int> arr = {4, 5, 2, 6, 3, 5, 3, 4, 1, 3, 5};
    sortByFrequency(arr);
    for (auto p = arr.begin(); p != arr.end(); p++) {
      cout << *p << " ";
    }
    cout << endl;
    return 0;
}
