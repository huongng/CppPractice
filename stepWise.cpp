#include <iostream>
#include <iomanip>

using namespace std;

bool stepWise(int** arr, int target, int trow, int tcol)
{
    int row = 0;
    int col = tcol - 1;

    while (row <= trow - 1 && col >= 0) {
	if (target < arr[row][col]) {
	    col--;
	}
	else if (target > arr[row][col]) {
	    row++;
	}
	else return true;
    }
    return false;
}

void print_array(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++) {
	for (int j = 0; j < col; j++) {
    	    cout << setw(5);
	    cout << arr[i][j];
	}
	cout << endl;
    }
}

int main()
{
    int COL = 10;
    int ROW = 12;
    int ** num_arr = new int*[ROW];
    int start = 1;
    for (int i = 0; i < ROW; i++) {
	num_arr[i] = new int[COL];
	int j = 0;
	for (j = 0; j < COL; j++) {
	    num_arr[i][j] = start++;
	}
    }

    print_array(num_arr, ROW, COL);

    cout << stepWise(num_arr, 150, ROW, COL) << endl;
    return 0;
}
