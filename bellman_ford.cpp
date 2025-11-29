#include<bits/stdc++.h>
using namespace std;

class edge
{
    public:
    int u,v,c;
    edge(int u,int v,int c)
    {
        this->u=u;
        this->v=v;
        this->c=c;
    }
};

const int N=1e5+5;
int dis[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Enter node and edge: " << endl;
    int n,e;
    cin >> n >> e;
    vector<edge> edgeList;
    cout << "Enter vertex:u,vertex:v and cost:c " << endl;
    while(e--)
    {
        int u,v,c;
        cin >> u >> v >> c;
        edgeList.push_back(edge(u,v,c));
    }
    for(int i=0;i<n;++i)
    {
        dis[i]=INT_MAX;
    }
    
    int src;
    cout << "Enter source: " << endl;
    cin >> src;
    dis[src]=0;

    // relax edge n-1 time
    for(int i=1;i<=n-1;++i)
    {
        for(edge ed:edgeList)
        {
            int u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]<INT_MAX && dis[u]+c<dis[v])
            {
                dis[v]=dis[u]+c;
            }
        }
    } 

    //check negarive cycle
    bool cycle =false;
    for(edge ed:edgeList)
    {
        int u,v,c;
        u=ed.u;
        v=ed.v;
        c=ed.c;
        if(dis[u]<INT_MAX && dis[u]+c<dis[v])
        {
            cycle=true;
            break;
        }
    }
    if(cycle) 
    {
        cout << "cycle found,no answer" << endl;
        return 0;
    }

    // print distance
    for(int i=0;i<n;++i)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}