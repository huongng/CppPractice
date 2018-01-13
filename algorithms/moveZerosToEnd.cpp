#include <iostream>
#include <vector>

using namespace std;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = a;
}
void moveZerosDown(vector<int>& arr);
int main()
{
    vector<int> arr = {1, 3, 0, 8, 12, 0, 4, 0 , 7};
    moveZerosDown(arr);
    return 0;
}

void moveZerosDown(vector<int>& arr)
{
    // 1, 3, 0, 8, 12, 0, 4, 0, 7
    // 1, 3, 8, 12, 4, 7, 0, 0, 0

    // 1 3 8 12 0 0 4 0 7
    // 1 3 8 12 4 0 0 0 7
    int zero_count = 0;
    int zero_pos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // if arr[i] != 0 and there's a 0
        // swap the 2 nums and update zero_pos = i
        if (zero_count) {
            if (arr[i] != 0) {
                swap(arr[i], arr[zero_pos]);
                zero_pos = i;
            }
        }
        // if arr[i] == 0 and there's a 0
        // move to next num
        // if arr[i] == 0 and there's no 0
        // set zero_pos = i
        else {
            if (arr[i] == 0) zero_pos = i;
        }
    }
}