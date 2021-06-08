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
    cin>>n;
    std::vector<int>coin(n);
    std::vector<int> ans;
    for(i=0;i<n;i++)
        cin>>coin[i];
    target=accumulate(coin.begin(),coin.end(),0);
    int dp[n+1][target+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=target;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else if(j<coin[i-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j-coin[i-1]]+dp[i-1][j];
           // cout<<dp[i][j]<<" ";
        }
       // cout<<"\n";
    }
    for(i=1;i<=target;i++){
        if(dp[n][i]!=0)
            ans.pb(i);
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)
        cout<<x<<" ";   
 
}
 










