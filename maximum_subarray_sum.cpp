#include <bits/stdc++.h>
using namespace std;

long long maxCrossingSum(vector<int> &a, int l, int m, int r)
{
    long long leftSum = LLONG_MIN, sum = 0;

    // left half
    for (int i = m; i >= l; i--)
    {
        sum += a[i];
        leftSum = max(leftSum, sum);
    }

    long long rightSum = LLONG_MIN;
    sum = 0;

    // right half
    for (int i = m + 1; i <= r; i++)
    {
        sum += a[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

long long MSS(vector<int> &a, int l, int r)
{
    if (l == r)
        return a[l];

    int m = (l + r) / 2;

    long long leftAns = MSS(a, l, m);
    long long rightAns = MSS(a, m + 1, r);
    long long crossAns = maxCrossingSum(a, l, m, r);

    return max({leftAns, rightAns, crossAns});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << MSS(a, 0, n - 1) << "\n";

    return 0;
}
