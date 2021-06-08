#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
ll n,m;
 
void dkstra(std::vector<ll>adj[], map<pair<ll,ll>,ll>mp)
{
    priority_queue<pair<ll,ll>,std::vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    std::vector<ll> dist(n+1,1e14);
    pq.push(mk(0,1));
    dist[1]=0;
    while(!pq.empty())
    {
        ll u=pq.top().second;
        ll d=pq.top().first;
        pq.pop();
        if(dist[u]<d)
            continue;
        for(auto x:adj[u])
        {
            ll z=mp[{u,x}];
            if(dist[x]>d+z){
                dist[x]=z+d;
                pq.push(mk(dist[x],x));
            }
        }
    }
   for(ll i=1;i<=n;i++)
    cout<<dist[i]<<" ";
    return ;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    cin>>n>>m;
    map<pair<ll,ll>,ll>mp;
    std::vector<ll>adj[n+1];
    while(m--){
        ll u,v,cost;
        cin>>u>>v>>cost;
        adj[u].pb(v);
        if(mp[{u,v}]==0)
            mp[{u,v}]=cost;
        else
            mp[{u,v}]=min(mp[{u,v}],cost);
    }
    dkstra(adj,mp);
    return 0;
}
 
 




