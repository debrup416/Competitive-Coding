#include<bits/stdc++.h>
using namespace std;

void kahnsAlgo(vector<int>adj[],vector<int>&inderge, int vertex)
{
    queue<int>qq;
    std::vector<int> ans;
    for(int i=0;i<inderge.size();i++)
    {
        if(inderge[i]==0)
            qq.push(i);
    }
    int count=0;
    while(!qq.empty())
    {
        int curr=qq.front();
        qq.pop();
        for(auto x:adj[curr])
        {
            inderge[x]--;
            if(inderge[x]==0)
                qq.push(x);
        }
        ans.push_back(curr);
        count++;
    }
    if((count!=vertex))
        cout<<"Not DAG";
    else
    {
        for(auto x:ans)
            cout<<x<<" ";
    }

} 

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    std::vector<int> adj[vertex];
    std::vector<int> inderge(vertex,0);
   
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        inderge[v]++;
    }

    kahnsAlgo(adj,inderge,vertex);

    return 0;
}


