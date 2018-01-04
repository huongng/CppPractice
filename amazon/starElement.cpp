#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void starElements(vector<int>& arr)
{
    vector<int> right = {-1};
    int size = arr.size();

    int sstar = -1;
    for (int i = size - 2; i >= 0; i--) {
        right.push_back(max(arr[i], right[size - i - 2]));
        //if (arr[i + 1] == right.back()) sstar = arr[i + 1];
    }

    // Remove duplicate
    right.erase( unique( right.begin(), right.end() ), right.end() );
    right[0] = arr[size - 1];
    // Reverse vector
    reverse(right.begin(), right.end());
    for (unsigned int i = 0; i < right.size(); i++) {
        cout << right[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++) {
        if (arr[i] > right.front())
            sstar = arr[i];
    }
    cout << sstar << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int size;
        cin >> size;
        vector<int> arr(size);
        for (int j = 0; j < size; j++)
        {
            cin >> arr[j];
        }
        starElements(arr);
    }
    return 0;
}