#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 998244353
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pi pair<ll,ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
int n;
 
void dfs(int curr,std::vector<int> adj[], std::vector<bool> &visited)
{
    visited[curr]=true;
    for(auto x:adj[curr])
    {
        if(!visited[x]){
            dfs(x,adj,visited);
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i,m;
    cin>>n>>m;
    std::vector<bool> visited(n+1,false);
    std::vector<int> adj[n+1];
    std::vector<int> ans;
    for(i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    for(i=1;i<=n;i++){
        if(!visited[i]){
            ans.pb(i);
            dfs(i,adj,visited);
        }
    }
    int t=ans.size()-1;
    cout<<t<<"\n";
    for(i=1;i<=t;i++)
        cout<<ans[i]<<" "<<ans[i]-1<<"\n";
     
    return 0; 
}
 
 



