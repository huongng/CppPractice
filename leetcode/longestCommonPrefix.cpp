#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPrefixUtils(string s1, string s2)
{
    string res;
    int l1 = s1.length();
    int l2 = s2.length();
    for (int i = 0, j = 0; i < l1 && j < l2; i++, j++) {
	if (s1.at(i) != s2.at(j)) break;
	res += s1.at(i);
    }
    return res;
}

string findLCP(vector<string>& strs, int low, int high)
{
    string s1, s2;
    if (low == high) return strs.at(low);
    int mid = (low + high) / 2;

    s1 = findLCP(strs, low, mid);
    s2 = findLCP(strs, mid+1, high);
    return longestPrefixUtils(s1, s2);
}

string longestCommonPrefix(vector<string>& strs)
{
    int low = 0;
    int high = strs.size() - 1;

    return findLCP(strs, low, high);
}

/* Comparing vertically
   e.g:
   geeksforgeeks
   geeks
   geezer
   -> 'gee'
 */
string fasterLCPMethod(vector<string>& strs)
{
    string prefix;
    if (strs.size() == 0) return prefix;
    for (int idx = 0; ; idx++) {
	for (int i = 0; i < strs.size(); i++) {
	    if (idx >= strs[i].size() || strs[0][idx] != strs[i][idx]) {
		return prefix;
	    }
	}
	prefix += strs[0][idx];
    }
    return prefix;
}

int main()
{
    vector<string> strs = {"geeksforgeeks", "geek", "geezer" };
    vector<string> strs1 = {"a"};
    cout << longestCommonPrefix(strs1) << endl;
    cout << fasterLCPMethod(strs) << endl;
    return 0;
}
