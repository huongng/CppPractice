/***
Input :            10
             /   /    \   \
            2  34    56   100
           / \        |   / | \
          77  88      1   7  8  9

Output : 10
         2 34 56 100
         77 88 1 7 8 9

Input :             1
             /   /    \   \
            2  3      4    5
           / \        |  /  | \
          6   7       8 9  10  11
Output : 1
         2 3 4 5
         6 7 8 9 10 11
***/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
void traverse_tree(map<int, vector<int> >& m, int root)
{
    // Check if root has child nodes
    if (m.find(root) == m.end()) {
	cout << root << endl;
	return;
    }
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
	int n = q.size();
	while (n > 0) {
	    int temp = q.front();
	    cout << temp << endl;
	    q.pop();
	    // push to queue child nodes of temp
	    for (auto p = m[temp].begin(); p != m[temp].end(); p++) {
		q.push(*p);
	    }
	    n--;
	}
    }
}
int main()
{
    map<int, vector<int> > mm = {{1, {2,3,4,5}}, {2, {6,7}}, {4, {8}}, {5, {9,10,11}}};
    traverse_tree(mm, 1);
    return 0;
}
