#include<bits/stdc++.h>
using namespace std;

bool is_cycle_Util(std::vector<int> adj[],vector<int> visited,int curr)
{
    if(visited[curr]==2)
        return true;
    visited[curr]=1;
    bool flag=false;
    for(int i=0;i<adj[curr].size();i++)
    {
        if(visited[adj[curr][i]]==1)
            visited[adj[curr][i]]=2;
        else
        {
            flag=is_cycle_Util(adj,visited,adj[curr][i]);
            if(flag==true)
                return true;
        }
    }
    return false;
     
}

bool is_cycle(int vertex,std::vector<int> adj[])
{
     std::vector<int> visited(vertex,0);
     bool flag=false;
     for(int i=0;i<vertex;i++)
     {
        visited[i]=1;
        for(int j=0;j<adj[i].size();j++)
        {
            flag=is_cycle_Util(adj,visited,adj[i][j]);
            if(flag==true)
                return true;
        }
        visited[i]=0;
     }
     return false;
}

int main()
{
    int N,edge;
    cin>>N>>edge;
    std::vector<int> adj[N];
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
     
    if(is_cycle(N,adj))
        cout<<"Cyclic";
    else
        cout<<"No Cycle";
    return 0;
    
}


