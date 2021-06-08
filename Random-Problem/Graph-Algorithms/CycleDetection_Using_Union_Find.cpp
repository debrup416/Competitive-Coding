#include<bits/stdc++.h>
using namespace std;
                                             
std::vector<int> dsup;


int find(int node)
{
    if(dsup[node]==-1)
        return node;
    return find(dsup[node]);

}

void union_op(int fromP,int toP)
{
    dsup[fromP]=toP;
}


bool is_cylic(vector<pair<int,int>>adj)
{
    for(auto x:adj)
    {
        int fromP=find(x.first);
        int toP=find(x.second);

        if(fromP==toP)
            return true;
        union_op(fromP,toP);
    }
    return false;
}


int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    vector<pair<int,int>>adj;
    
   dsup.resize(vertex,-1);
    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj.push_back({u,v});
       
    }

    if(is_cylic(adj))
        cout<<"Cyclic";
    else
        cout<<"Not Cyclic";

    return 0;
}


