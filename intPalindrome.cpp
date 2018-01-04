#include <iostream>

using namespace std;

bool is_palindrome(int num)
{
    if (num < 0) return false;
    int rev_num = 0;
    while (rev_num < num) {
	rev_num = rev_num * 10 + num % 10;
	num /= 10;
    }

    return rev_num == num || num == rev_num / 10;
}
int main()
{
    int num;
    cin >> num;
    cout << is_palindrome(num) << endl;
    return 0;
}
