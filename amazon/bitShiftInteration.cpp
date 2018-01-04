#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string bitRepresentation(int n)
{
    string bits = "";
    while (n) {
	if (n & 1) bits += "1";
	else bits += "0";
	n >>= 1;
    }

    reverse(bits.begin(), bits.end());

    return bits;
}

void extendBit(string& bits)
{
    size_t i = 0;
    while (i < bits.length()) {
	if (bits[i] == '1')
	    bits.insert(i + 1, "0");
	else
	    bits.insert(i + 1, "1");
	i += 2;
    }
    return;
}
int main()
{
    int test, m, k, n;
    string bits, mkn;

    cin >> test;
    if (test < 1 || test > 100) return -1;

    for (int t = 0; t < test; t++) {
	cin >> m >> k >> n;
	if (m < 1 || m > 50 || n < 1 || n > 10) return -1;

	bits = bitRepresentation(m);
	for (int i = 0; i < n; i++)
	    extendBit(bits);

	if (k >= bits.length()) return -1;
	cout << bits << endl;
	cout << bits[k] << endl;
    }
    return 0;
}
