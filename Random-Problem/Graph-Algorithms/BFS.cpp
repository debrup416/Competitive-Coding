#include<bits/stdc++.h>
using namespace std;
  
 class Graph
  {
     int V;
     list<int>*adj;
     deque<int>*dq;
     bool *visited;

  public:
      Graph(int V)
      {
        this->V=V;
        adj=new list<int>[V];
        dq=new deque<int>[V];
        visited=new bool[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
      }

      void addEdge(int v,int w)
      {
        adj[v].push_back(w);
      }

      void BFS(int v)
      {

            visited[v]=true;
            dq->push_back(v);
            while(!dq->empty())
            {
                v=dq->front();
                cout<<v<<" ";
                dq->pop_front();
                for(auto it=adj[v].begin();it!=adj[v].end();it++)
                {
                    if(!visited[*it])
                    {
                        visited[*it]=true;
                        dq->push_back(*it);
                    }
                }
            }
      }
      
  }; 

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.BFS(2);
}



