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
    int n,target,val,j,i;
    cin>>n>>target;
    std::vector<int> v;
    for(i=0;i<n;i++)
    {
        cin>>val;
        v.pb(val);
    }
     
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=target;j++)
        {
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
                dp[i][j]=INT_MAX-1;
            else if(v[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
        }
         
    }
    if(dp[n][target]!=INT_MAX-1)
        cout<<dp[n][target];
    else
        cout<<-1;
   /* cout<<"\n";
    cout<<sizeof(dp)/1000000;*/
 
 
    return 0; 
}











