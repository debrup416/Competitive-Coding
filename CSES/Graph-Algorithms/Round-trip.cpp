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
 
int startgp,endgp;
 
bool dfs(int curr,int parent ,std::vector<int> adj[],std::vector<bool> &visited,std::vector<int> &track)
{
    visited[curr]=true;
    track[curr]=parent;
 //   cout<<curr<<" "<<parent<<"\n";
    for(auto x:adj[curr])
    {
        if(x==parent)
            continue;
        if(visited[x]){
            startgp=x;
            endgp=curr;
            return true;
        }
        if(!visited[x]){
            if(dfs(x,curr,adj,visited,track))
                return true;
        }
    }
    return false;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;
    std::vector<int> adj[n+1];
    std::vector<bool> visited(n+1,0);
    std::vector<int> track(n+1,0);
    std::vector<int> ans;
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    for(i=1;i<=n;i++){
        if(!visited[i])
        {
            track.clear();
            if(dfs(i,-1,adj,visited,track)){
                    int var=endgp;
                    ans.pb(endgp);
                    while(var!=startgp){
                        ans.pb(track[var]);
                        var=track[var];
                    }
                    ans.pb(endgp);
                    cout<<ans.size()<<"\n";
                    for(auto x:ans)
                        cout<<x<<" ";
              return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
 
     
    return 0; 
}
 



