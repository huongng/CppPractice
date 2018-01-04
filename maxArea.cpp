#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int maxArea(vector<int>& height)
{
    int area = 0;
    int length = height.length();
    int l = 0;
    int r = length - 1;

    while (l < r) {
	area = max(area, (r - l) * min(height[l], height[r]));
	if (height[l] < height[r]) l++;
	else r--;
    }
    return area;
}

int main()
{
    vector<int> heights;
    return 0;
}
