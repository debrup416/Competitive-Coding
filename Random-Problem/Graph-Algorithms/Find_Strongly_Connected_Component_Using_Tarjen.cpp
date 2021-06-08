#include<bits/stdc++.h>
using namespace std;

int vertex;

void DFS(vector<int>adj[],int u, vector<int>& disc,vector<int>& low, stack<int>&stk,vector<bool>&presentInStack)
{
   // cout<<adj[u][0]<<" ";
    static int time=0;
    disc[u]=time;
    low[u]=time;
    time+=1;
    stk.push(u);
    presentInStack[u]=true;

    for(int v:adj[u])
    {
        if(disc[v]==-1)
        {
            DFS(adj,v,disc,low,stk,presentInStack);
            low[u]=min(low[u],low[v]);
        }
        else if(presentInStack[v]==true)
            low[u]=min(low[u],disc[v]);
    }

    if(low[u]==disc[u])
    {
        cout<<"SCC is : ";
        while(stk.top()!=u)
        {
            cout<<stk.top()<<" ";
            presentInStack[stk.top()]=false;
            stk.pop();
        }
        cout<<stk.top()<<"\n";
        presentInStack[stk.top()]=false;
        stk.pop();
    }
}

void findSSC_Tarjan(vector<int>adj[] )
{
    vector<int>disc(vertex,-1),low(vertex,-1);
    vector<bool>presentInStack(vertex,false);
    stack<int>stk;

    for(int i=0;i<vertex;i++)
    {
        if(disc[i]==-1)
            DFS(adj,i,disc,low,stk,presentInStack);
    }
}

int main()
{
    int edge;
    cin>>vertex>>edge;
    vector<int>adj[vertex]; 
    for(int i=0;i<edge;i++)
    {
        int src,dst;
        cin>>src>>dst;
        adj[src].push_back(dst);
    }

    findSSC_Tarjan(adj);
    return 0;
}

