#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back

void shortest_path_undirectedGraph_unitDistance(int vertex, vector<int>adj[])
{
    vector<int>dist(vertex,INT_MAX);
    queue<int>q;
    q.push(0);
    dist[0]=0;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        for(auto node:adj[curr]){
            if(dist[node]>1+dist[curr]){
                dist[node]=1+dist[curr];
                q.push(node);
            }
        }
    }

    for(int i=0;i<vertex;i++)
        cout<<"Distance of vertex "<<i<<" from 0 : "<<dist[i]<<"\n";

    return ; 
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
        adj[v].pb(u);
    }

    shortest_path_undirectedGraph_unitDistance(vertex,adj);

    return 0;
}




