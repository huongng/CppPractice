#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int largestSum(vector<int>& arr)
{
    int max_so_far = arr[0];
    int cur_max = arr[0];
    int size = arr.size();
    bool isAllNeg = true;
    int min_so_far = arr[0];
    for (int i = 1; i < size; i++) {
	if (arr[i] > 0) isAllNeg = false;
	min_so_far = min(arr[i], min_so_far);
	cur_max = max(arr[i], cur_max + arr[i]);
	max_so_far = max(cur_max, max_so_far);
    }
    if (isAllNeg) return min_so_far;
    return max_so_far;
}

int largestSumWithIndices(vector<int>& arr, int& s, int& e)
{
    int max_so_far = 0;
    int cur_max = 0;
    int s_offset = 0;
    for (int i = 0; i < arr.size(); i++) {
	cur_max += arr[i];
	if (cur_max > max_so_far) {
	    max_so_far = cur_max;
	    e = i;
	    s =  s_offset;
	}
	else if (cur_max < 0) {
	    s_offset = i + 1;
	    cur_max = 0;
	}
    }
    return max_so_far;
}
int main()
{
    vector<int> nums = { -3, 2, 7, -9, 2, 5, -1 };
    vector<int> nums2 = {-7, -2, -9, -3, -5 };
    int s = 0;
    int e = 0;
    cout << largestSumWithIndices(nums, s, e) << endl;
    cout << "start: " << s << ", end: " << e << endl;
    cout << largestSum(nums2) << endl;
    return 0;
}
