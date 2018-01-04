#include <iostream>
#include <string>

using namespace std;

string convert(string s, int rowNums)
{
    string arr[rowNums];
    int row = 0, direction = 0;
    int n = s.length();
    for (int i = 0; i < n; i++) {
	if (row == 0) direction = 0;
	else if (row == rowNums - 1) direction = 1;

	arr[row] += s[i];
	row = (direction)? (row-1) : (row+1);
    }
    string finalString = "";
    for (int i = 0; i < rowNums; i++) {
	finalString += arr[i];
    }
    return finalString;
}
int main()
{
    string input;
    int line;
    cin >> input;
    cin >> line;
    cout << convert(input, line) << endl;
    return 0;
}
