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

// Function to subtract two matrices
Matrix subtract(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Strassen's algorithm for matrix multiplication
Matrix strassen(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    // Base case: 1x1 matrix
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
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

        // Calculating the 7 products, recursively (p1, p2...p7)
        Matrix P1 = strassen(add(A11, A22), add(B11, B22));              // P1 = (A11 + A22) * (B11 + B22)
        Matrix P2 = strassen(add(A21, A22), B11);                        // P2 = (A21 + A22) * B11
        Matrix P3 = strassen(A11, subtract(B12, B22));                   // P3 = A11 * (B12 - B22)
        Matrix P4 = strassen(A22, subtract(B21, B11));                   // P4 = A22 * (B21 - B11)
        Matrix P5 = strassen(add(A11, A12), B22);                        // P5 = (A11 + A12) * B22
        Matrix P6 = strassen(subtract(A21, A11), add(B11, B12));         // P6 = (A21 - A11) * (B11 + B12)
        Matrix P7 = strassen(subtract(A12, A22), add(B21, B22));         // P7 = (A12 - A22) * (B21 + B22)

        // Calculating C11, C12, C21, C22
        Matrix C11 = add(subtract(add(P1, P4), P5), P7);                 // C11 = P1 + P4 - P5 + P7
        Matrix C12 = add(P3, P5);                                        // C12 = P3 + P5
        Matrix C21 = add(P2, P4);                                        // C21 = P2 + P4
        Matrix C22 = add(subtract(add(P1, P3), P2), P6);                 // C22 = P1 + P3 - P2 + P6

        // Combining the 4 results into a single matrix
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
    // Example matrices (4x4)
    Matrix A = {{1, 2, 3, 4}, 
                {5, 6, 7, 8},
                {9, 10, 11, 12}, 
                {13, 14, 15, 16}};
                
    Matrix B = {{17, 18, 19, 20},
                {21, 22, 23, 24}, 
                {25, 26, 27, 28}, 
                {29, 30, 31, 32}};

    // Multiply matrices A and B using Strassen's algorithm
    Matrix C = strassen(A, B);

    // Print result
    cout << "Resultant matrix: " << endl;
    printMatrix(C);

    return 0;
}
