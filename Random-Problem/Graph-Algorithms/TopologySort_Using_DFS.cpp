#include<bits/stdc++.h>
using namespace std;
 
void topo(vector<int>adj[],vector<bool>&visited,int node,stack<int>&ans)
{
   if(visited[node]==true)
    return ;
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
            topo(adj,visited,adj[node][i],ans);
    }
    ans.push(node);
}

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    vector<int>adj[vertex];
    vector<bool>visited(vertex,false);
    stack<int>ans;
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=0;i<vertex;i++)
        if(!visited[i])
            topo(adj,visited,i,ans);

    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }

    return 0;
}


