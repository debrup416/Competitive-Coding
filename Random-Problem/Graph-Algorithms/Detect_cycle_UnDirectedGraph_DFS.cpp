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

int dfs_cycle(int node, int parent, vector<int> adj[],vector<bool>&visited)
{
    visited[node]=true;
    for(auto x:adj[node])
    {
        if(x==parent)
            continue;
        if(visited[x]==true)
            return 1;
        if(dfs_cycle(x,node,adj,visited))
            return 1;
    }
    return 0;
}

int detect_cycle_undirected_graph(int vertex,vector<int>adj[])
{
    vector<bool>visited(vertex,false);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            if(dfs_cycle(i,-1,adj,visited))
                return 1;
    }
    return 0;
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
    
    cout<<detect_cycle_undirected_graph(vertex,adj);
	
    return 0; 
}

