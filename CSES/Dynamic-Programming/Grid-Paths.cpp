#include<bits/stdc++.h>
#include<stdlib.h>
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
    int n,i,j;
    cin>>n;
    std::vector<string> vs(n);
    for(i=0;i<n;i++)
    	cin>>vs[i];
    n--;
    int dp[n+1][n+1];
    i=0;
    while(i<=n && vs[0][i]=='.')
    	dp[0][i++]=1;
    while(i<=n)
    	dp[0][i++]=0;
    i=0;
    while(i<=n && vs[i][0]=='.')
    	dp[i++][0]=1;
    while(i<=n)
    	dp[i++][0]=0;
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(vs[i][j]=='*')
    			dp[i][j]=0;
    		else
    			dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;	 
    	}
    	 
    }
    cout<<dp[n][n]%mod<<"\n";
    
    
    return 0; 
}
 





