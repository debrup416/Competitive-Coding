#include<bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   int n,z,i,j;
   string X,Y;
   cin>>X>>Y;
   z=X.length();
   n=Y.length();
  
   int dp[z+1][n+1];
   
  memset(dp,0,sizeof(dp[0][0])*(z+1)*(n+1));
   int ans=-1;
   for(i=1;i<=z;i++)
   {
	   for(j=1;j<=n;j++)
	   {
		if(X[i-1]==Y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
		else
			dp[i][j]=0;//max(dp[i-1][j],dp[i][j-1]);
		ans=max(ans,dp[i][j]);
	   }
	 
   }
   cout<<ans;
	
}













