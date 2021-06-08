#include<bits/stdc++.h>
using namespace std;
 
class Graph
{
    int V;
    list<int>*adj;
    void DFSUtil(int v,bool visited[])
    {
        visited[v]=true;
        cout<<v<<" ";

        for(auto it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visited[*it])
                DFSUtil(*it,visited);
        }

    }
public:
    void connectedComponents()
    {
        bool *visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++)
        {  
            if(!visited[i])
                DFSUtil(i,visited);
            cout<<"\n";
        }
    }

    void addEdge(int v,int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    
};

int main()
{
    Graph g(5); // 5 vertices numbered from 0 to 4 
    g.addEdge(1, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 4); 
  
    cout << "Following are connected components \n"; 
    g.connectedComponents(); 
  
    return 0; 

}








