#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int _3sumClosest(vector<int>& v, int target)
{
    int result;
    int minimum = INT_MAX;

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() - 2; i++) {
	for (int j = i + 1, k = v.size() - 1; j < k; ) {
	    int sum = v[i] + v[j] + v[k];
	    int diff = abs(target - sum);

	    if (diff == 0) {
		return sum;
	    }

	    if (diff < minimum) {
		minimum = diff;
		result = sum;
	    }

	    if (sum < target) j++;
	    else k--;
	}
    }
    return result;
}
int main()
{
    vector<int> v = {1, 2, -4, -1};
    cout << _3sumClosest(v, 1) << endl;
    return 0;
}
