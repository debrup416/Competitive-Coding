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
    int n,target,i,j;
    cin>>n>>target;
    std::vector<int>coin(n),profit(n);
    for(i=0;i<n;i++)
        cin>>coin[i];
    for(i=0;i<n;i++)
        cin>>profit[i];
    int dp[n+1][target+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=target;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(j>=coin[i-1])
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-coin[i-1]]+profit[i-1]);
            else
                dp[i][j]=dp[i-1][j];
            //cout<<dp[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<dp[n][target];
    
 
}
 
 




