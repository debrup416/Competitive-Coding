#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back


int detect_cycle_directed_graph_bfs(int vertex, vector<int> adj[])
{
    queue<int>q;
    vector<int>indegree(vertex,0);
    for(int i=0;i<vertex;i++)
    {
        for(auto x:adj[i])
            indegree[x]++;
    }

    for(int i=0;i<vertex;i++)
    {
        if(indegree[i]==0)
             q.push(i);
    }

    int cnt=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cnt++;
        for(auto x:adj[node])
        {
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
    }
    if(cnt==vertex)
        return 0;
    return 1;
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

    if (detect_cycle_directed_graph_bfs(vertex, adj))
        cout << "Yes Cyclic";
    else
        cout << "No Cycle";

    return 0;
}



