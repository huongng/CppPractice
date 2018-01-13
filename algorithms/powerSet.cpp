#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generatePowerSet(vector<int>& num_set)
{
    int size = pow(2, num_set.size());
    for (int i = 0; i < size; i++) {
        int flag = i;
        int count = 0;
        while (flag) {
            if (flag & 1) cout << num_set[count];
            count++;
            flag >>= 1;
        }
    }
}
int main()
{
    vector<int> num_set = { 1, 2, 3 };
    generatePowerSet(num_set);
    return 0;
}