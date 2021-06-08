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
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,q;
    cin>>n>>m>>q;
    std::vector<ll> temp(n,1e14);
    std::vector<std::vector<ll> > mat(n,temp);
    while(m--)
    {
        ll u,v,cost;
        cin>>u>>v>>cost;
        u--;
        v--;
        mat[u][v]=min(mat[u][v],cost);
        mat[v][u]=mat[u][v];
    }
    for(ll i=0;i<n;i++)
        mat[i][i]=0;
    for(ll k=0;k<n;k++)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(mat[i][k]==1e14 || mat[k][j]==1e14)
                    continue;
                else if(mat[i][k]+mat[k][j]<mat[i][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        if(mat[a][b]==1e14)
            cout<<-1<<"\n";
        else
            cout<<mat[a][b]<<"\n";
    }
 
    // for(auto xx:v)
    // {
    //     for(auto x:xx)
    //         cout<<x<<" ";
    //     cout<<"\n";
    // }
 
}
 
 



