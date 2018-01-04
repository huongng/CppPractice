#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void rotate_right(int** matrix, int r, int c)
{
    int n = r;
    for (int l = 0; l < n / 2; l++) {
	//
	int first = l;
	int last = n - first - 1;
	for (int i = first; i < last; i++) {
	    int offset = i - first;
	    int top = matrix[first][i];
	    matrix[first][i] = matrix[last - offset][first];
	    matrix[last - offset][first] = matrix[last][last - offset];
	    matrix[last][last - offset] = matrix[i][last];
	    matrix[i][last] = top;
	}
    }
    return;
}

void rotate_left(int** matrix, int r, int c)
{
    int n = r;
    for (int l = 0; l < n/2; l++) {
	int first = l;
	int last = n - first - 1;
	for (int i = first; i < last; i++) {
	    int offset = i - first;
	    int top = matrix[first][i];
	    matrix[first][i] = matrix[first + offset][last];
	    matrix[first + offset][last] = matrix[last][last - offset];
	    matrix[last][last - offset] = matrix[last - offset][first];
	    matrix[last - offset][first] = top;
	}
    }
    return;
}
void rotate_rows(int**& matrix, int r, int c)
{
    for (int i = 0; i < r; i++) {
	int temp = matrix[i][c-1];
	int j;
	for (j = c - 1; j > 0; j--) {
	    matrix[i][j] = matrix[i][j - 1];
	}
	matrix[i][j] = temp;
    }
    return;
}
void create_matrix(int**& matrix, int r, int c, string input)
{
    int offset = 0;    
    matrix = new (int*);
    for (int i = 0; i < r; i++) {
	matrix[i] = new int;
	for (int j = 0; j < c; j++) {
	    matrix[i][j] = input[j + offset] - '0';
	}
	offset += c;
    }
    return;
}
void print_matrix_line(int**& matrix, int r, int c)
{
    for (int i = 0; i < r; i++) {
	for (int j = 0; j < c; j++) {
	    cout << matrix[i][j] << " ";
	}
    }
    cout << endl;
}

void clear_matrix(int**& matrix, int r)
{
    for (int i = 0; i < r; i++) {
	delete[] matrix[i];
    }
    delete[] matrix;
    return;
}
int main()
{
    int test, m, n, k;
    cin >> test;
    for (int t = 0; t < test; t++) {
	int **matrix;	
	string input;
	
	cin >> m >> n >> k;
	cin.ignore();
	getline(cin , input);
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	create_matrix(matrix, m, n, input);

	rotate_rows(matrix, m, n);
	print_matrix_line(matrix, m, n);

	clear_matrix(matrix, m);
    }
    return 0;
}
