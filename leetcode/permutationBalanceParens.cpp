#include <string>
#include <vector>
#include <iostream>

using namespace std;

void printPermutations(vector<string>& res, int open, int close, string s)
{
    if (open == 0 && close == 0) {
	cout << s << endl;
	res.push_back(s);
	return;
    }
    if (open > 0) {
	printPermutations(res, open - 1, close + 1, s + '{');
    }
    if (close > 0) {
	printPermutations(res, open, close - 1, s + '}');
    }
    return;
}

void printPermutations2(vector<string>& res, int n, int open, int close, string s)
{
    if (open > close) {
	s += ')';
	printPermutations2(res, n, open, close + 1, s);
    }
    if (open < n) {
	s += '(';
	printPermutations2(res, n, open + 1, close, s);
    }
    if (close == n) {
	res.push_back(s);
	return;
    }
}

int main()
{
    int n;
    string result;
    vector<string> res;
    vector<string> res2;
    cin >> n;

    printPermutations(res, n, 0, "");
    printPermutations2(res2, n, 0, 0, "");
    cout << res.size() << endl;
    cout << res2.size() << endl;
    return 0;
}
