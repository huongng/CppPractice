/**
 * Sort elements by frequency in decreasing order
 * If 2 elements have the same frequency, sort by appearing order
 **/
#include <iostream>
#include <vector>
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
    void inorder(Node* node, Node* tracks[]&, int& index);
public:
    BST() : root(nullptr) {}
    void insert(int data, int index);
    void inorder(Node* tracks[]&, int& index);
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
void BST::inorder(Node* tracks[]&, int& index)
{
    if (root == nullptr) return;
    inorder(root, tracks, index);
}
void BST::inorder(Node* node, Node* tracks[]&, int& index)
{
    if (node == nullptr) return;
    inorder(node->left, tracks, index);
    cout << node->id <<endl;
    tracks[index++] = node;
    cout << tracks[index] << endl;
    inorder(node->right, tracks, index);
}

void sortByFrequency(vector<int>& arr)
{
    // build a BST from arr, with each tree node having structure {val, frequency, first index}
    BST tree;
    for (int i = 0; i < arr.size(); i++) {
        tree.insert(arr[i], i);
    }
    // Traverse inorder and put frequency in a 2-D array of (frequency, Node*)
    Node* tracks[tree.getSize()];
    int index = 0;
    tree.inorder(tracks, index);
    //cout << tracks[0]->id << endl;
    //cout << index << endl;
}
int main()
{
    vector<int> arr = {4, 5, 2, 6, 3, 5, 3, 4, 1, 3, 5};
    sortByFrequency(arr);
    return 0;
}