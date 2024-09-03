#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

// Function to add two matrices
Matrix add(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Function to multiply two matrices using divide and conquer
Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        // Divide matrices into 4 submatrices
        int newSize = n / 2;
        Matrix A11(newSize, vector<int>(newSize)), A12(newSize, vector<int>(newSize)),
               A21(newSize, vector<int>(newSize)), A22(newSize, vector<int>(newSize));
        Matrix B11(newSize, vector<int>(newSize)), B12(newSize, vector<int>(newSize)),
               B21(newSize, vector<int>(newSize)), B22(newSize, vector<int>(newSize));

        // Dividing matrix A into A11, A12, A21, A22
        for (int i = 0; i < newSize; ++i)
            for (int j = 0; j < newSize; ++j) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];
            }

        // Dividing matrix B into B11, B12, B21, B22
        for (int i = 0; i < newSize; ++i)
            for (int j = 0; j < newSize; ++j) {
                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }

        // Recursively multiply submatrices
        Matrix C11 = add(multiply(A11, B11), multiply(A12, B21));
        Matrix C12 = add(multiply(A11, B12), multiply(A12, B22));
        Matrix C21 = add(multiply(A21, B11), multiply(A22, B21));
        Matrix C22 = add(multiply(A21, B12), multiply(A22, B22));

        // Combine results into final matrix C
        for (int i = 0; i < newSize; ++i)
            for (int j = 0; j < newSize; ++j) {
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const Matrix& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example matrices (2x2)
    Matrix A = {{1, 2,3,2}, {3, 4,2,1},{2,4,5,3}};
    Matrix B = {{5, 6,3,7}, {7, 8,3,6},{2,4,5,3}};

    // Multiply matrices A and B
    Matrix C = multiply(A, B);

    // Print result
    cout << "Resultant matrix: " << endl;
    printMatrix(C);

    return 0;
}
