#include<bits/stdc++.h>
using namespace std;

void addEdge(std::vector<int> adj[],int u,int v)
{
	adj[u].push_back(v);
	//adj[v].push_back(u);
}

void pnt(std::vector<int> adj[],int V)
{
	for(int v=0;v<V;v++)
	{
		cout<<"Adjacent List of vertex "<<v<<"head->";
		for(auto x:adj[v])
				cout<<"->"<<x;
		cout<<"\n";
	}
}

int main()
{
	int V=5;
	std::vector<int> adj[V];

	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3 );
	addEdge(adj,2,3);
	addEdge(adj,3,2);
	addEdge(adj,4,1);
	addEdge(adj,4,2);
	addEdge(adj,4,3);
	addEdge(adj,4,4);
	 
	pnt(adj,V);
}
