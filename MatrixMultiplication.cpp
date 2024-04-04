#include <iostream>
using namespace std;

int main() {
    int row1, col1, row2, col2;

    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> row1 >> col1;

    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> row2 >> col2;

    if (col1 != row2) {
        cout << "Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }

    int A[row1][col1], B[row2][col2], result[row1][col2];

    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Result of matrix multiplication:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
