/***
Input: "abbba", "abb", "ba", "abcd", "abdc", "adbc", "aabddc"
Output:
"ab": 3
"abcd": 4
 ***/
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<string>& a)
{
    map<string, int>res;
    for (auto p = a.begin(); p != a.end(); p++) {
      vector<bool> check(256);
      for (int i = 0; i < p->length(); i++) {
	if(!check[(*p)[i]]) {
	  check[(*p)[i]] = true;
	}
      }

      string str = "";
      for (int i = 0; i < 256; i++) {
	if (check[i]) str+= i;
      }
      res[str]++;
    }
    for (auto p = res.begin(); p != res.end(); p++) {
      cout << p->first << ": " << p->second << endl;
    }
}
int main() {
    vector<string> v = {"abbba", "abb", "ba", "abcd", "abdc", "adbc", "aabddc"};
    solution(v);
    return 0;
}
