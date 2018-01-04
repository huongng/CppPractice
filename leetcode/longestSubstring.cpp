#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>* char_array = new vector<bool>();
        int max = 0;
        
        if (s.length() == 0 || s.length() == 1) return s.length();
        for (int i = 0; i < s.length(); i++) {
            cout << i << " " << max << " "  << s << endl;
            *char_array[s[i]] = true;
            if (i+1 == s.length() || char_array[s[i+1]]) {
                if (max <= i+1)
                    max = i+1;
                char_array = new vector<bool>();
                s = s.substr(i+1, s.length());
                i = -1;
            }
        }
        if (max == 0) return s.length();
        return max;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line = "abcabcde";
    cout << Solution().lengthOfLongestSubstring(line);
    /*
    while (getline(cin, line)) {
        string s = stringToString(line);
        
        int ret = Solution().lengthOfLongestSubstring(line);

        string out = to_string(ret);
        cout << out << endl;
	}*/
    return 0;
}
