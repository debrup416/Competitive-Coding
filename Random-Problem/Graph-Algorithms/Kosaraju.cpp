#include<bits/stdc++.h>
using namespace std;

int vertex;
vector<bool>visited;
stack<int>stk;

void DFS1(int node,vector<int>adj[])
{
    visited[node]=true;
    for(int i:adj[node])
    {
        if(visited[i]==false)
            DFS1(i,adj);
    }
    stk.push(node);
}

void reverse(vector<int>adj[], vector<int>rev[])
{
    for(int i=0;i<vertex;i++)
    {
        for(auto x:adj[i])
            rev[x].push_back(i);
    }

}

void DFS2(int i,vector<int> rev[])
{
    cout<<i<<" ";
    visited[i]=true;
    for(auto j:rev[i])
    {
        if(!visited[j])
            DFS2(j,rev);
    }
}

void findSSCs(vector<int> adj[],vector<int> rev[])
{
    for(int i=0;i<vertex;i++)
    {
        if(!visited[i])
            DFS1(i,adj);
    }

    reverse(adj,rev);
    
    for (int i = 0; i<vertex; ++i)
        visited[i]=0;
      
        cout<<"Strongly Connected Componenet are :\n";
    while(!stk.empty())
    {
        int curr=stk.top();
        stk.pop();
        if(visited[curr]==false)
        {
            DFS2(curr,rev);
            cout<<"\n";
        }

    }
     
}

 
int main()
{
    int edge;
    cin>>vertex>>edge;
    vector<int>adj[vertex];
    vector<int>rev[vertex];
    visited.resize(vertex,false);

    for(int i=0;i<edge;i++)
    {
        int src,dst;
        cin>>src>>dst;
        adj[src].push_back(dst);
    }
     
    findSSCs(adj,rev);
    return 0;
}


