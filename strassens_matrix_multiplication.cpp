#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> addMat(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

vector<vector<int>> subMat(vector<vector<int>> A, vector<vector<int>> B)
{
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B)
{

    int n = A.size();
    if (n == 1)
        return {{A[0][0] * B[0][0]}};

    int k = n / 2;

    vector<vector<int>>
        A11(k, vector<int>(k)), A12(k, vector<int>(k)),
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

    auto M1 = strassen(addMat(A11, A22), addMat(B11, B22));
    auto M2 = strassen(addMat(A21, A22), B11);
    auto M3 = strassen(A11, subMat(B12, B22));
    auto M4 = strassen(A22, subMat(B21, B11));
    auto M5 = strassen(addMat(A11, A12), B22);
    auto M6 = strassen(subMat(A21, A11), addMat(B11, B12));
    auto M7 = strassen(subMat(A12, A22), addMat(B21, B22));

    vector<vector<int>> C(n, vector<int>(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];         // C11
            C[i][j + k] = M3[i][j] + M5[i][j];                           // C12
            C[i + k][j] = M2[i][j] + M4[i][j];                           // C21
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j]; // C22
        }

    return C;
}

void print(vector<vector<int>> M)
{
    for (auto &r : M)
    {
        for (auto &v : r)
            cout << v << " ";
        cout << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter n : ";
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

    auto C = strassen(A, B);

    cout << "Result:\n";
    print(C);
}
