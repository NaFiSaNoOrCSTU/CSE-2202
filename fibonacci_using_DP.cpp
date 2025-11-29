#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int dp[N];

long long fibo(int n)
{
    if (n == 0 || n == 1)
    {
        dp[n] = n;
        return n;
    }
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cout << "Enter n: " << endl;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << "last value: " << fibo(n) << endl;
    cout << "fibonacci series : ";
    for (int i = 0; i <= n; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}