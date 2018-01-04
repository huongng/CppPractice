#include <iostream>
#include <vector>
#include <map>

using namespace std;
int main()
{
  vector<int> nums = {3, 2, 4};
  map<int, int> hash;
  for (int i = 0; i < 3; i++) {
    int diff = 6 - nums[i];
    if (hash.find(diff)->first > 0) {
	cout << diff << endl;
	int first = hash.find(diff)->first;
	int second = i;
	cout << first << " " << second << endl;
	return 0;
	//return vector<int>{first, second};
    }
    hash.insert(pair<int, int>(diff, i));
  }
  
  cout << hash.count(3) << endl;
  return 0;
}
