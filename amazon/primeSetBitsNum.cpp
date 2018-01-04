#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void generatePrime(int n)
{
    // create an array of number from 2 to n
    bool arr[n + 1] = {false};
    // set p = 2
    int p = 2;
    // multiply p with each number from 2 to n
    for (int i = 2; i*i <= n; i++) {
	if (!arr[i] && i <= n) p = i;
	for (int j = 2; j <= n; j++) {
	    if (p * j <= n) {
		arr[p * j] = true;
	    }
	}
    }

    for (int i = 2; i <= n; i++) {
	if (!arr[i]) cout << i << endl;
    }

    return;
}

void sieveOfEratosthenes(int n, bool** arr)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
	if (prime[p]) {
	    for (int i = p*2; i <=n; i+=p) {
		prime[i] = false;
	    }
	}
    }

    *arr = prime;
}

int countBits(int n)
{
    int count = 0;
    for (int i = 0; i < 32; i++) {
	if ((1 << i) & n) count++;
    }
    return count;
}
int main()
{
    int start, end;
    int total = 0;
    cin >> start;
    cin >> end;
    bool * arr = new bool;
    sieveOfEratosthenes(end, &arr);
    for (int i = start; i <= end; i++) {
	int count = countBits(i);
	if (arr[count]) total++;
    }

    cout << total << endl;
    return 0;
}
