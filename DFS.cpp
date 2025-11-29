#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<vector<int>> mat(N);
bool vis[N];
void dfs(int src)
{
    cout << src << " ";
    vis[src] = true;
    for (int child : mat[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    dfs(src);
    return 0;
}