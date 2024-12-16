#include <iostream>
#include <vector>
using namespace std;

// Function to compute the prefix function (lps array)
vector<int> prefix(string P) {
    int m = P.length();
    vector<int> arr(m, 0); // Initialize the prefix array with size m and default value 0
    int k = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; ++i) {
        while (k > 0 && P[k] != P[i]) {
            k = arr[k - 1]; // Adjust k using the prefix array
        }
        if (P[k] == P[i]) {
            ++k;
        }
        arr[i] = k;
    }
    return arr;
}

// KMP Algorithm
void KMP(string T, string P) {
    int n = T.length();
    int m = P.length();

    if (m == 0 || n == 0) {
        cout << "Invalid input: Text or pattern is empty." << endl;
        return;
    }

    vector<int> arr = prefix(P); // Compute the prefix array
    int p = 0; // Index for pattern

    for (int i = 0; i < n; ++i) {
        while (p > 0 && T[i] != P[p]) {
            p = arr[p - 1]; // Adjust p using the prefix array
        }
        if (T[i] == P[p]) {
            ++p;
        }
        if (p == m) { // A match is found
            cout << "Pattern found at index " << i - m + 1 << endl;
            p = arr[p - 1]; // Continue searching for the next match
        }
    }
}

int main() {
    string T, P;
    cout << "Text: ";
    cin >> T;
    cout << "Pattern: ";
    cin >> P;
    KMP(T, P);
    return 0;
}
