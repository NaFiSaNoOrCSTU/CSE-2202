#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,e;
    cin >> n >> e;
    ll adj[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            adj[i][j]=INT_MAX;
            if(i==j) adj[i][j]=0;
        }
    }
    while(e--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a][b]=c;
    }
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}