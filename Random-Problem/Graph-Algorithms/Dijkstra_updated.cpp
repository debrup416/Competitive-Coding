#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back


void Dijkstra(int src,int vertex, vector<pair<int,int>>adj[])
{
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
    vector<int>dist(vertex,INT_MAX);
    dist[src]=0;
    pq.push(mk(0,src));
    while(!pq.empty())
    {
        int curr=pq.top().second;
        pq.pop();
        for(auto it:adj[curr])
        {
             int next=it.first;
             int cost=it.second;
             if(dist[next]>dist[curr]+cost){
                 dist[next]=dist[curr]+cost;
                 pq.push(mk(dist[next],next));
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
        adj[v].push_back({u,cost});       
    }
    int src;
    cin>>src;
    Dijkstra(src,vertex,adj);

    return 0;
}






