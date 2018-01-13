#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;
void print_vector(vector<int>& v) 
{
    cout << "{ ";
    for (auto p = v.begin(); p != v.end(); p++) {
      cout << *p << ",";
    }
    cout << " }" << endl;
}
void print_iter(vector<vector<int>::iterator>& v)
{
    for (auto p = v.begin(); p != v.end(); p++) {
      cout << *(*p) << endl;
    }
}
bool findFirstCommoneElement(vector<vector<int> >& v, int& res)
{
    vector<vector<int>::iterator> its;
    int size = v.size();
    for (auto p = v.begin(); p != v.end(); p++) {
      its.push_back(p->begin());
    }
    bool found = false;

    while (!found) {
	found = true;
	for (int i = 0; i < size - 1; i++) {
	    if (its[i] == v[i].end()) return false;
	    if (*its[i] < *its[i+1]) {
		found = false;
		its[i]++;
	    }
	    else if (*its[i] > *its[i+1]) {
		found = false;
		its[i+1]++;
	    }
	    else {
		res = *its[i];
	    }
	}
    }
    return found;
}

int main()
{
    vector<vector<int> > a = {{0, -90, 45, 10, 4},
			     {4, 8, 90, 45},
			     {-1, -3, -5, -7, 10, 4},
			     {24, 35, 78, -90, 56, 4}};
    for (auto p = a.begin(); p != a.end(); p++) {
	sort(p->begin(), p->end());
	print_vector(*p);
    }
    int res;
    if(findFirstCommoneElement(a, res)) cout << res << endl;
    else cout << "No common element" << endl;
    return 0;
}
