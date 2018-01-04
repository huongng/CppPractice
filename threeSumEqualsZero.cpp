#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* Use HASH TABLE => O(n2) */
vector<vector<int>> _3sum(vector<int>& v)
{
    int n = v.size();
    vector<vector<int>> result;
    sort(v.begin(), v.end());
    cout << v[0] << endl;
    for (int i = 0; i < n; i++) {
	if (i > 0 && (v[i] == v[i - 1])) continue;
	for (int j = i +1, k = n - 1; j < k; ) {
	    int sum = v[j] + v[k] + v[i];
	    if (sum > 0) {
		k--;
		continue;
	    }
	    if (sum == 0) {
		cout << "found" << endl;
		vector<int> temp = {v[i], v[j], v[k]};
		result.push_back(temp);
	    }
	    do {
		j++;
	    } while (j < k && (v[j] == v[j-1]));
	}
    }
    return result;
}

void print_vector(vector<int> v)
{
    for (auto p = v.begin(); p != v.end(); p++) {
	cout << *p << " ";
    }
    return;
}
	
int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4 };
    vector<int> v1 = {-2, 0, 0, 2, 2 };
    vector<vector<int>> res = _3sum(v);
    for (auto p = res.begin(); p != res.end(); p++) {
	print_vector(*p);
	cout << endl;
    }
    return 0;
}
