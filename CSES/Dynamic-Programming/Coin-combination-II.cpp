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
 
int dp[102][1000007];
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,target,val,i,j;
    cin>>n>>target;
    std::vector<int> v;
    for(i=0;i<n;i++)
    {
        cin>>val;
        v.pb(val);
    }
 
    for(i=1;i<=target;i++)
        dp[0][i]=0;
     for(i=0;i<=n;i++)
        dp[i][0]=1;
    for(i=1;i<=n;i++)
    { 
        for(j=1;j<=target;j++)
        {
           if(v[i-1]<=j)
               dp[i][j]=dp[i-1][j]%mod +dp[i][j-v[i-1]]%mod;
           else
               dp[i][j]=dp[i-1][j]%mod;
                
        }
    }    
 
    cout<<dp[n][target]%mod;
    return 0; 
}














