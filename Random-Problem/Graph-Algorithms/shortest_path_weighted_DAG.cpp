#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back

void topological_sort(int node, stack<int>&topo, vector<bool>&vis, vector<pair<int, int>> adj[])
{
    vis[node]=true;
    for(auto x:adj[node])
    {
        if(!vis[x.first])
            topological_sort(x.first,topo,vis,adj);
    }
    topo.push(node);
}

void shortest_path_weighted_DAG(int src,int vertex, vector<pair<int,int>>adj[])
{
   stack<int>topo;
   vector<bool>vis(vertex,false);
    for(int i=0;i<vertex;i++)
    {
        if(!vis[i])
            topological_sort(i,topo,vis,adj);
    }

    vector<int>dist(vertex,INT_MAX);
    dist[src]=0;

    while (!topo.empty())
    {
        int curr=topo.top();
        topo.pop();
        if(dist[curr]!=INT_MAX){
            for(auto x:adj[curr])
            {
                if(dist[x.first]>dist[curr]+x.second)
                    dist[x.first]=dist[curr] + x.second;
            }
        }
    }

    for(int i=0;i<vertex;i++)
        cout<<"Dist of node "<<i<<" from "<<src<<" : "<<dist[i]<<"\n";
    
    return ;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vertex, edge;
    cin >> vertex >> edge;
    vector<pair<int,int>> adj[vertex];
    for (int i = 0; i < edge; i++)
    {
        int u, v,cost;
        cin >> u >> v>>cost;
        adj[u].push_back({v,cost});        
    }

    shortest_path_weighted_DAG(0,vertex,adj);

    return 0;
}





