#include<bits/stdc++.h>
using namespace std;
  
int vertex;
vector<bool>processed;
vector<int>value;
vector<int>parent;

int selectMinVertex( )
{
    int minimum=INT_MAX,index;
    for(int i=0;i<vertex;i++)
    {
        if(processed[i]==false && value[i]<minimum)
        {
            index=i;
            minimum=value[i];
        }
    }
    return index;
}

void Dijkstra(vector<int>adj[],int matrix[100][100])
{
    value[0]=0;

    for(int i=0;i<vertex-1;i++)
    {
        int U=selectMinVertex();
         processed[U]=true;

        for(auto x:adj[U])
        {
            if(processed[x]==false)
            {
                if(value[U]+matrix[U][x]<value[x])
                {
                    value[x]=value[U]+matrix[U][x];
                    parent[x]=U;
                }
            }              
        }
    }
    cout<<"Cost of shortest Path from vertex 0 to another vertex respectively:\n";
    for(int i=1;i<vertex;i++)
        cout<<value[i]<<" ";
    cout<<"\nDijkstra Graph will be :\n";
    for(int i=1;i<vertex;i++)
        cout<<"src: "<<parent[i]<<"  Dst: "<<i<<"  Cost: "<<matrix[parent[i]][i]<<"\n";
}

int main()
{
    int edges;
    cin>>vertex>>edges;
    vector<int>adj[vertex];
    int matrix[100][100];
    value.resize(vertex,INT_MAX);
    processed.resize(vertex,false);
    parent.resize(vertex,-1);

    for(int i=0;i<edges;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back(v);
        adj[v].push_back(u);
        matrix[u][v]=cost;
        matrix[v][u]=cost;
    }

    Dijkstra(adj,matrix);
    return 0;

}