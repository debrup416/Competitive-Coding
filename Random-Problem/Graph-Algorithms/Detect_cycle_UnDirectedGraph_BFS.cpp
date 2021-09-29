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

int bfs_cylce(int node,vector<int> adj[],vector<bool>&visited)
{
    visited[node]=true;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(!q.empty())
    {
        int curr = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto x:adj[curr])
        {
            if(x==par)
                continue;
            if(visited[x]==true)
                return 1;
            visited[x]=true;
            q.push({x,curr});
        }
    }
    return 0;
}

int detect_cycle_undirected_graph(int vertex,vector<int>adj[])
{
    vector<bool>visited(vertex,false);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            if(bfs_cylce(i,adj,visited))
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

