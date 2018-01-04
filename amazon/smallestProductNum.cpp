#include <iostream>
#include <stack>

using namespace std;

int smallestNum(int n)
{
    stack<int> digits;

    // Edge cases
    if (n <= 9 && n >= 0) return n;
    for (int i = 9; i >= 2 && n > 1; i--) {
	while (n % i == 0) {
	    digits.push(i);
	    n /= i;
	}
    }

    // if true, no number k can be found
    if (n != 1) return -1;

    // has a stack of number
    int k = 0;
    while (!digits.empty()) {
	k = k * 10 + digits.top();
	digits.pop();
    }

    return k;
}

int main()
{
    int n;
    cin >> n;
    cout << smallestNum(n) << endl;

    return 0;
}
