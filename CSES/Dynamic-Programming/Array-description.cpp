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
    int n,m,i,j;
    ll ans=0;
    cin>>n>>m;
    std::vector<int> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    ll dp[n+2][m+2];
    memset(dp,0,sizeof(dp));
    for(i=1;i<=m;i++){
        if(v[0]==0 || v[0]==i)
            dp[0][i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(v[i]==0 || v[i]==j)
                dp[i][j]=(dp[i-1][j-1]%mod+dp[i-1][j]%mod+dp[i-1][j+1]%mod)%mod;
           // cout<<dp[i][j]<<" ";
        }
       // cout<<"\n";
    }
    for(i=1;i<=m;i++)
        ans=(ans%mod+dp[n-1][i]%mod)%mod;
    cout<<ans;
}
 
 
 


