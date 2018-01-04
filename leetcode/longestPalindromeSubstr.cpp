#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Precondition: get a valid string
 * Postcondition: print out the longest palindrome substring
 * and return the length
 **/
int longestPalindromeSubstr(string s)
{
    int maxLength = 1;
    int n = s.length();
    // table[i][j] will be false if substring s[i...j] is not
    // a palindrome
    // else table[i][j] is true
    bool table[n][n] = {false}; // all set to false now

    // All substring of length 1 is palindrome
    maxLength = 1;
    for (int i = 0; i < n; i++)
	table[i][i] = true;

    // check for substring of length 2
    int palindromeStart = 0;
    for (int i = 0; i < n - 1; i++) {
	if (s[i] == s[i+1]) {
	    table[i][i+1] = true;
	    maxLength = 2;
	    palindromeStart = i;
	}
    }

    // check for substrings with length > 2
    for (int cur_len = 3; cur_len <= n; cur_len++) {
	// fix the starting index
	for (int i = 0; i <= n - cur_len + 1; i++) {
	    int j = i + cur_len - 1;
	    if (table[i+1][j-1] && s[i] == s[j]) {
		palindromeStart = i;
		if (cur_len > maxLength) maxLength = cur_len;
		// update table
		table[i][j] = true;
	    }
	}
    }

    // print out palindrome substring
    cout << s.substr(palindromeStart, maxLength) << endl;
    return maxLength;
}
int main()
{
    string s;
    cin >> s;
    cout << longestPalindromeSubstr(s) << endl;
    return 0;
}
