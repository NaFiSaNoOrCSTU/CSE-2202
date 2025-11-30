#include <bits/stdc++.h>
using namespace std;

int tsp(int n, vector<vector<int>> &dist, vector<bool> &visited, int currPos, int count, int cost, int &ans)
{
    if (count == n && dist[currPos][0] > 0)
    {
        ans = min(ans, cost + dist[currPos][0]);
        return ans;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[currPos][i] > 0)
        {
            visited[i] = true;
            tsp(n, dist, visited, i, count + 1, cost + dist[currPos][i], ans);
            visited[i] = false;
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of cities: " << endl;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter distance matrix: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    vector<bool> visited(n, false);
    visited[0] = true;
    int ans = INT_MAX;

    ans = tsp(n, dist, visited, 0, 1, 0, ans);
    cout << "Minimum cost: " << ans << endl;

    return 0;
}
