#include<bits/stdc++.h>
using namespace std;
 
vector<bool>setMst;
vector<int>value;
int vertex;

int selectMinVertex()
{
    int var=INT_MAX,index;
    for(int i=0;i<vertex;i++)
    {
        if(setMst[i]==false && value[i]<var)
        {
            var=value[i];
            index=i;
        }
    }
    return index;
}

void prims(vector<int>adj[],int matrix[100][100])
{
    setMst.resize(vertex,false);
    value.resize(vertex,INT_MAX);
    int parent[vertex];

    parent[0]=-1;
    value[0]=0;

    for(int i=0;i<vertex-1;i++)
    {
        int U=selectMinVertex();
        setMst[U]=true;

        for(auto x:adj[U])
        {
            if(setMst[x]==false && matrix[U][x]<value[x])
            {
                value[x]=matrix[U][x];
                parent[x]=U;
            }
        }
    }
    for(int i=1;i<vertex;i++)
        cout<<"Edge between "<<parent[i]<<" to "<<i<<" And Edge cost is "<<matrix[i][parent[i]]<<"\n";

}

int main()
{
    int edge;
    cin>>vertex>>edge;
    vector<int>adj[vertex];
    int matrix[100][100];
    memset(matrix,0,sizeof(matrix));

    for(int i=0;i<edge;i++)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        adj[u].push_back(v);
        adj[v].push_back(u);
        matrix[u][v]=cost;
        matrix[v][u]=cost;
    }

    prims(adj,matrix);
    return 0;

}