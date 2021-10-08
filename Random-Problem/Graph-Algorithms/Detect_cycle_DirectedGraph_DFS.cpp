#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back

int cycle_dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&inDfs)
{
    visited[node] = 1;
    inDfs[node] = 1;
    for(auto x:adj[node])
    {
        if(!visited[x]){
            if (cycle_dfs(x, adj, visited, inDfs))
                return 1;
        }
        else if(inDfs[x])
            return 1;
    }
    inDfs[node]=0;
    return 0;
}

int detect_cycle_directed_graph(int vertex, vector<int> adj[])
{
    vector<int>visited(vertex,0),inDfs(vertex,0);
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i]){
            if(cycle_dfs(i,adj,visited,inDfs))
                return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vertex, edge;
    cin >> vertex >> edge;
    vector<int> adj[vertex];
    for (int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
    }

    if (detect_cycle_directed_graph(vertex, adj))
        cout << "Yes Cyclic";
    else
        cout << "No Cycle";

    return 0;
}


