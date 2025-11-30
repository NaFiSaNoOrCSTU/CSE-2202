#include <bits/stdc++.h>
using namespace std;

pair<int, string> LCS(string a, string b)
{
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    string lcs = "";

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(lcs.begin(), lcs.end());

    return {dp[n][m], lcs};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cout << "Enter two strings: " << endl;
    cin >> a >> b;

    auto ans = LCS(a, b);
    cout << "LCS Length: " << ans.first << endl;  
    cout << "LCS String: " << ans.second << endl; 
    return 0;
}
