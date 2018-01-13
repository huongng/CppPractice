#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int shortestPalindromeGenerate(string& input);
void lps_generate(string& patter, vector<int>& lps);
int main()
{
    string input = "AACECAAAA";
    string pat = "AA";
    cout << shortestPalindromeGenerate(input) << endl;
}

int shortestPalindromeGenerate(string& input)
{
    string orig = input;
    for (int i = input.length() - 1; i >= 0; i--) {
        input += input[i];
    }
    vector<int> lps(input.length());
    // reverse and append to the end of input
    // AACECAAAA$AAAACECAA
    // generate lps array for the new string
    lps_generate(input, lps); 
    for (auto p = lps.begin(); p != lps.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;
    // find the longest suffix-prefix for that pair
    int orig_length = orig.length();
    int num_of_appends = orig_length - lps[input.length() - 1];

    // append the end of input that is not in the suffix-prefix part to the top of string
    for (int i = 0; i < num_of_appends; i++) {
        orig.insert(orig.begin(), input[orig_length - i - 1]);
    }
    cout << orig << endl;
    return num_of_appends;
}
void lps_generate(string& pattern, vector<int>& lps)
{
    // aabacaa => [0, 1, 0, 1, 0, 1, 2]
    int length = pattern.length();
    int i = 1;
    int len = 0;
    lps[0] = 0;
    while (i < length)
    {
        if (pattern[i] == pattern[len]) {
            lps[i] = len + 1;
            i++;
            len++;
        }
        else {
            if (len > 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}