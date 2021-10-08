#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back


void prims(int vertex, vector<pair<int,int>>adj[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

    vector<int>key(vertex,INT_MAX);
    vector<bool>inMst(vertex,false);
    vector<int>parent(vertex,-1);
    parent[0]=-1;
    key[0]=0;
    pq.push(mk(0,0));
    while(!pq.empty())
    {
        int u;
        u = pq.top().second;
        pq.pop();
        inMst[u] = true;

        for (auto x : adj[u])
        {
            int v = x.first;
            int wt = x.second;
            if (inMst[v] == false && wt < key[v])
            {
                key[v] = wt;
                parent[v] = u;
                pq.push(mk(key[v], v));
            }
        }
    }

    for(int i=1;i<vertex;i++)
        cout<<"Node from "<<i<<" to "<<parent[i]<<" and Weight is "<<key[i]<<"\n";
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
   
    prims(vertex,adj);

    return 0;
}



