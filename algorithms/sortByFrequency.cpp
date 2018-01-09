/**
 * Sort elements by frequency in descending order.
 * If 2 elements have the same frequency, print the one that has smaller value first.
 * E.g: {4, 5, 2, 6, 3, 5, 3, 4, 1, 3, 5} => {5, 5, 5, 3, 3, 3, 4, 4, 2, 6, 1}
 **/
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}
void sortByFrequency(vector<int>& arr)
{
    // create a map of numbers and their (frequency, first index)
    map<int, int> numbers;
    for (int i = 0; i < arr.size(); i++) {
        numbers[arr[i]]++;
    }
    // put frequency and first index to a 2-D array
    pair<int, int> ps[numbers.size()];
    int i = 0;
    for (auto p = numbers.begin(); p != numbers.end(); p++) {
        ps[i] = make_pair(p->first, p->second);
        i++;
    }
    sort(ps, ps + numbers.size(), compare);
    int offset = 0;
    for (int i = 0; i < numbers.size() && offset < arr.size(); i++) 
    {
        int freq = ps[i].second;
        int j = 0;
        while (freq--) {
            arr[offset] = ps[i].first;
            offset++;
        }
    }
}
int main()
{
    vector<int> arr = {4, 5, 2, 6, 3, 5, 3, 4, 1, 3, 5};
    sortByFrequency(arr);
    for (auto p = arr.begin(); p != arr.end(); p++) {
        cout << *p << " ";
    }
    cout << endl;
    return 0;
}