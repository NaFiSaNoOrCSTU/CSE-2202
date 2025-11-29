#include <bits/stdc++.h>
using namespace std;

// Add two matrices
vector<vector<int>> addMat(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Subtract two matrices
vector<vector<int>> subMat(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Divide and Conquer multiplication
vector<vector<int>> dcMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();

    if (n == 1)
    {
        return {{A[0][0] * B[0][0]}};
    }

    int k = n / 2;

    // Submatrices
    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k)),
        A21(k, vector<int>(k)), A22(k, vector<int>(k)),
        B11(k, vector<int>(k)), B12(k, vector<int>(k)),
        B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    // Recursively calculate submatrices
    auto C11 = addMat(dcMultiply(A11, B11), dcMultiply(A12, B21));
    auto C12 = addMat(dcMultiply(A11, B12), dcMultiply(A12, B22));
    auto C21 = addMat(dcMultiply(A21, B11), dcMultiply(A22, B21));
    auto C22 = addMat(dcMultiply(A21, B12), dcMultiply(A22, B22));

    // Combine results
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }

    return C;
}

// Print matrix
void printMat(const vector<vector<int>> &M)
{
    int n = M.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter matrix size (power of 2): ";
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n)), B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    vector<vector<int>> C = dcMultiply(A, B);

    cout << "Resultant Matrix:\n";
    printMat(C);

    return 0;
}
