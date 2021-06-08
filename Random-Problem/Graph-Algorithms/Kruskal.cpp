#include<bits/stdc++.h>
using namespace std;
 
 
struct node{
    int parent;
    int rank;
};

struct Edge{
    int src;
    int dst;
    int wt;
};

vector<node>dsuf;
vector<Edge>mst;

int find(int val)
{
    if(dsuf[val].parent==-1)
        return val;
    return dsuf[val].parent=find(dsuf[val].parent);
}

void union_op(int fromP,int toP)
{
    if(dsuf[fromP].rank<dsuf[toP].rank)
        dsuf[fromP].parent=toP;
    else if(dsuf[toP].rank<dsuf[fromP].rank)
        dsuf[toP].parent=fromP;
    else
    {
         dsuf[toP].parent=fromP;
         dsuf[fromP].rank++;
    }

}

bool cmp(Edge a,Edge b)
{
    return a.wt<b.wt;
}

void Kruskals(vector<Edge>&edge_lists, int V,int E)
{
    sort(edge_lists.begin(),edge_lists.end(),cmp);

    int i=0,j=0;
    while(i<V-1 && j<E)
    {
        int fromP=find(edge_lists[j].src);
        int toP=find(edge_lists[j].dst);

        if(fromP==toP)
        {
            j++;
            continue;
        }

        union_op(fromP,toP);
        mst.push_back(edge_lists[j]);
        i++;
    }

}

void print(std::vector<Edge> &edge_lists)
{
    for(auto p:edge_lists)
        cout<<"Src :"<<p.src<<" Dst: "<<p.dst<<"  wt: "<<p.wt<<"\n";

}


int main()
{
    int vertex,totalEdges;
    cin>>vertex>>totalEdges;

    dsuf.resize(vertex);
    for(int i=0;i<vertex;i++)
    {
        dsuf[i].parent=-1;
        dsuf[i].rank=0;
    }

    vector<Edge>edge_lists;
    Edge temp;
    for(int i=0;i<totalEdges;i++)
    {
        int from,to,weight;
        cin>>from>>to>>weight;
        temp.src=from;
        temp.dst=to;
        temp.wt=weight;
        edge_lists.push_back(temp);
    }

    Kruskals(edge_lists,vertex,totalEdges);
    print(mst);
    
    return 0;
}