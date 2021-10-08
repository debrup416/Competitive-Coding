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






/*=======================================================*/





#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define mod 1000000007
#define fc(da, db) if (abs(da - db) < le - 9)
#define pi pair<ll, ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back


void prims(int vertex, vector<pair<int,int>>adj[])
{
    vector<int>key(vertex,INT_MAX);
    vector<bool>inMst(vertex,false);
    vector<int>parent(vertex,-1);
    parent[0]=-1;
    key[0]=0;

    for(int i=0;i<vertex-1;i++)
    {
        int u,val=INT_MAX;
        for(int k=0;k<vertex;k++)
        {
            if(inMst[k]==false && key[i]<val){
                val=key[i];
                u=i;
            }
        }
        inMst[u]=true;

        for(auto x:adj[u])
        {
            int v=x.first;
            int wt=x.second;
            if(inMst[v]==false && wt<key[v]){
                key[v]=wt;
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<vertex;i++)
        cout<<"Node from "<<i<<" to "<<parent[i]<<" and Weight is "<<key[i]<<"\n";
    return ;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vertex, edge;
    cin >> vertex >> edge;
    vector<pair<int,int>> adj[vertex];
    for (int i = 0; i < edge; i++)
    {
        int u, v,cost;
        cin >> u >> v>>cost;
        adj[u].push_back({v,cost}); 
        adj[v].push_back({u,cost});       
    }
   
    prims(vertex,adj);

    return 0;
}











