#include<iostream>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

void mcm(vector<vector<int>>&m, vector<vector<int>>&s, vector<int>p) {
    int n = p.size() - 1;

    // Initialize the diagonal of m to 0
    for (int i = 0; i < n; i++) {
        m[i][i] = 0;
    }

    // l is the chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; ++i) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printParenthesis(vector<vector<int>>&s, int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
    } else {
        cout << "(";
        printParenthesis(s, i, s[i][j]);
        printParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> p = {10, 20, 30, 40, 30}; // dimensions of matrices
    int n = p.size() - 1;

    vector<vector<int>> m(n, vector<int>(n, 0));  // Cost matrix
    vector<vector<int>> s(n, vector<int>(n, 0));  // Parenthesis matrix

    mcm(m, s, p);

    // Output the Cost Matrix (m)
    cout << "Cost Matrix (m):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << m[i][j] << " ";
        }
        cout << endl;
    }

    // Output the Parenthesis Matrix (s)
    cout << "\nParenthesis Matrix (s):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(8) << s[i][j] << " ";
        }
        cout << endl;
    }

    // Print the optimal parenthesization
    cout << "\nOptimal Parenthesization: ";
    printParenthesis(s, 0, n - 1);
    cout << endl;

    return 0;
}
