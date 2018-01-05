/***
       x * (x^2)^(n-1/2) if odd
x^n = (x^2)^(n/2) if even
***/
#include <iostream>
using namespace std;

int power(int x, int n)
{
    int res = 1;
    if (n == 0) return 1;

    res = power(x, n/2);
    // if n is odd
    if (n & 1) {
	return x * res * res;
    }
    n >>= 1;
    x *= x;
    return res;
}
int power_re(int x, int n)
{
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n & 1) return x * power_re(x * x, n / 2);
    return power(x*x, n/2) * power(x*x, n/2);
}
int power_iter(int x, int n)
{
    if (n == 0) return 1;
    int res = 1;
    while (n > 0) {
	// if even
	if (n & 1 == 0) {
	    res *= x * x;
	    n /= 2;
	}
	else {
	    res *= x;
	    x *= x;
	    n = (n - 1) / 2;
	}
    }
    return res;
}
int main()
{
    cout << power_re(3,3) << endl;
    cout << power_iter(3,3) << endl;
    return 0;
}
