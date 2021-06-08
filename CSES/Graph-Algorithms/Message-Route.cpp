#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pi pair<ll,ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
 
void bfs(std::vector<int> adj[], std::vector<bool> &visited,int n,std::vector<int> &track)
{
	queue<int>q;
	int p;
	q.push(1);
	while(!q.empty())
	{
		p=q.front();
		if(p==n)
			return;
		q.pop();
		if(adj[p].size()==0)
			return;
		for(auto x:adj[p])
		{
			if(!visited[x]){
				q.push(x);
				visited[x]=true;
				track[x]=p;
			}
		}
	}
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;
    std::vector<int> adj[n+1];
    std::vector<bool> visited(n+1,false);
    std::vector<int> ans;
    std::vector<int> track(n+1);
 
    for(i=0;i<m;i++)
    {
    	int u,v;
    	cin>>u>>v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
 
    bfs(adj,visited,n,track);
      if(!visited[n]){
    	cout<<"IMPOSSIBLE\n";
    	return 0;
    }
    ans.pb(n);
    int var=n;
    while(var!=1){
    	var=track[var];
    	ans.pb(var);
    }
  
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<"\n";
    for(auto x:ans)
    	cout<<x<<" ";
 
     
    return 0; 
}
 




