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
 
ll dp[5001][5001];
ll solve(std::vector<ll> &v,int i,int j)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j)
        return v[i];
    if(i+1==j)
        return max(v[i],v[j]);
    ll val=max(v[i]+min(solve(v,i+2,j),solve(v,i+1,j-1)),v[j]+min(solve(v,i+1,j-1),solve(v,i,j-2)));
    
    return dp[i][j]=val;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    std::vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
   memset(dp,-1,sizeof(dp));
   solve(v,0,n-1);
   cout<<dp[0][n-1];
    
}
 
 








