#include<bits/stdc++.h>
using namespace std;


struct node {
    int parent;
    int rank;
};
vector<node>dsuf;

int find(int v)
{
    if(dsuf[v].parent==-1)
        return v;
    return dsuf[v].parent=find(dsuf[v].parent);
}

void union_op(int fromP,int toP)
{
    if(dsuf[fromP].rank>dsuf[toP].rank)
        dsuf[toP].parent=fromP;
    else if(dsuf[fromP].rank<dsuf[toP].rank)
        dsuf[fromP].parent=toP; 
    else
    {
         dsuf[fromP].parent=toP; 
         dsuf[toP].rank +=1;
    }

}

bool is_cyclic(vector<pair<int,int>>&adj)
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
    dsuf.resize(vertex);
    for(int i=0;i<vertex;++i)     
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    for(int i=0;i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj.push_back({u,v});
    }

    if(is_cyclic(adj))
        cout<<"Cyclic";
    else
        cout<<"Not Cyclic";


    return 0;
}
