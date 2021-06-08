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
 
bool bfs(std::vector<int> adj[],std::vector<int> &color,int n,int curr)
{
    queue<int>q;
    q.push(curr);
    int p;
    color[curr]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(auto x:adj[p])
        {
            if(color[x]==color[p])
                return false;
            if(color[x]==-1){
                color[x]=(1-color[p]);
                q.push(x);
            }
        }
    }
    return true;
} 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,i;
    cin>>n>>m;
    std::vector<int> adj[n+1];
    std::vector<int> color(n+1,-1);
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(i=1;i<=n;i++){
        if(color[i]==-1){
            if(bfs(adj,color,n,i)==false){
                cout<<"IMPOSSIBLE\n";
                 return 0;
             }          
        }
    }
    for(i=1;i<=n;i++)
        cout<<color[i]+1<<" ";
 
     
    return 0; 
}





