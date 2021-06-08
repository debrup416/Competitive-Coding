#include<bits/stdc++.h>
using namespace std;

bool is_cycle_Util(std::vector<int> adj[],vector<bool> visited,int curr)
{
    if(visited[curr]==true)
            return true;
    visited[curr]=true;
    bool flag=false;
    for(int i=0;i<adj[curr].size();i++)
    {
        flag=is_cycle_Util(adj,visited,adj[curr][i]);
        if(flag==true)
            return true;
    }
    return false;
}

bool is_cycle(int vertex,std::vector<int> adj[])
{
    std::vector<bool> visited(vertex,false);
    bool flag=false;
    for(int i=0;i<vertex;i++)
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            flag=is_cycle_Util(adj,visited,adj[i][j]);
            if(flag==true)
                return true;
        }
        visited[i]=false;
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
    }
     
    if(is_cycle(N,adj))
        cout<<"Cyclic";
    else
        cout<<"No Cycle";
    return 0;
    
}


