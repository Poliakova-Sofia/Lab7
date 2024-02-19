#include <iostream>
using namespace std;

const int M = 20;
const int N = 20;
//  getting matrixs size
void get_matrix(int matrix[M][N], int& m, int& n);

/* Given a matrix of size M × N. For each row of the matrix with an odd number (1, 3, ...)
find the arithmetic mean of its elements. Do not use conditional operator.*/
void matrix21(int matrix[M][N], const int& m, const int& n);

/*Given a matrix of size M × N and an integer number K (1 ≤ K ≤ N). 
Insert a column of ones after the column with number K in the matrix. */
void matrix69(int matrix[M][N], const int& m, int& n, int k);
void resultMatrix69(int matrix[M][N], int m, int n);

int main() // menu
{
    int task_num; // declaration integer
    do {
        cout << " Enter task number (0 - exit): ";
        cin >> task_num; // input integer
        if (!cin) {
            cout << " Ups!" << endl; 
            continue; // error notification
        }
        switch (task_num) 
        {
            case 1: { // task1
                int matrix[M][N];
                int m, n;
                get_matrix(matrix, m, n);
                matrix21(matrix, m, n);
                break;
            }
            case 2: { // task2
                int matrix[M][N];
                int m, n, k;
                get_matrix(matrix, m, n);
                cout << "Enter the column number where to insert 1s : ";
                cin >> k;
                matrix69(matrix, m, n, k);
                resultMatrix69(matrix, m, n);
                break;
            }
            case 0: 
                cout << " Bye!" << endl; 
                break; // exit from the program
            default: 
                cout << " Wrong task number!" << endl; 
                // output for incorrect numbers
                break;
        }
    } while (task_num != 0); // end the program
    return 0;
}

// matrix_size
void get_matrix(int matrix[M][N], int& m, int& n) {
    do {
        // Input the size of the matrix
        cout << "Enter the number of rows (2-20) (M): ";
        cin >> m;
        cout << "Enter the number of columns (= Rows !!!) (2-20) (N): ";
        cin >> n;
    } while (n < 2 || n > N || m < 2 || m > M || m != n);

    // Input the elements of the matrix
    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// task1
void matrix21(int matrix[M][N], const int& m, const int& n) {
    // Output the arithmetic mean for odd-numbered rows
    cout << "Arithmetic mean for odd-numbered rows: " << endl;
    for (int i = 0; i < m; i += 2) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += matrix[i][j];
        }
        double average = static_cast<double> (sum) / n;
        cout << "Row " << i << ": " << average << endl;
    }
}

// task2
void matrix69(int matrix[M][N], const int& m, int& n, int k) {
    if (k < 1 || k > n) {
        cout << "Invalid column number!";
        return;
    }
    
    // Check if the new number of columns exceeds N
    if (n + 1 > N) {
        cout << "Cannot insert column, matrix is full!";
        return;
    }

    // Increase the number of columns by 1
    ++n;

    // Shift all columns to the right of k by one position to the right
    for (int j = n - 1; j > k; --j) {
        for (int i = 0; i < m; ++i) {
            matrix[i][j] = matrix[i][j - 1];
        }
    }

    // Insert a column with 1s at position k
    for (int i = 0; i < m; ++i) {
        matrix[i][k + 1] = 1;
    }
}

// results task2
void resultMatrix69(int matrix[M][N], int m, int n) {
    cout << "Resulting matrix:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << " " << matrix[i][j];
        }
        cout << endl;
    }
}
