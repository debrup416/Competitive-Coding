#include<bits/stdc++.h>
using namespace std;

typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pi pair<ll,ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back

int bipartite_dfs(int node, vector<int> adj[], vector<int> &color)
{
    for(auto x:adj[node])
    {
        if(color[x]==-1)
        {
            color[x]=1-color[node];
            if(!bipartite_dfs(x,adj,color))
                return 0;
        }
        else if(color[x]==color[node])
            return 0;
    }
    return 1;
}

int bipartite(int vertex,vector<int>adj[])
{
    vector<int>color(vertex,-1);
    for(int i=0;i<vertex;i++)
    {
        if(color[i]==-1)
        {
            color[i]=1;
            if (!bipartite_dfs(i, adj, color))
                return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vertex,edge;
    cin>>vertex>>edge;
    vector<int>adj[vertex];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (bipartite(vertex, adj))
        cout <<"Yes bipartite";
    else
        cout <<"No bipartite";

    return 0;
}



