#include <iostream>
#include <vector>
#include <climits>
#include <iomanip> // For formatted output
using namespace std;

void optimal_bst(vector<double> P, vector<double> C, int n, vector<vector<double>> &e, vector<vector<double>> &w, vector<vector<int>> &R) {
    // Initialize matrices
    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = C[i - 1];
        w[i][i - 1] = C[i - 1];
    }

    // Fill matrices for chain lengths 1 to n
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1; // Ending index of the chain
            e[i][j] = INT_MAX; // Initialize with a large value (infinity)
            w[i][j] = w[i][j - 1] + P[j - 1] + C[j]; // Update weight

            // Find the optimal root
            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    R[i][j] = r;
                }
            }
        }
    }
}

int main() {
    // Input probabilities for keys and dummy keys
    vector<double> P = {0.1, 0.2, 0.4}; // Probabilities for keys
    vector<double> C = {0.05, 0.1, 0.05, 0.05}; // Probabilities for dummy keys
    int n = P.size();

    // Declare matrices
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0)); // Cost matrix
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0)); // Weight matrix
    vector<vector<int>> R(n + 2, vector<int>(n + 1, 0));       // Root matrix

    // Compute Optimal BST
    optimal_bst(P, C, n, e, w, R);

    // Output matrices
    cout << "Cost Matrix (e):\n";
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(8) << fixed << setprecision(2) << e[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nWeight Matrix (w):\n";
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(8) << fixed << setprecision(2) << w[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nRoot Matrix (R):\n";
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << setw(8) << R[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
