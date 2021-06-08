/*
#include<bits/stdc++.h>
using namespace std;

//MEMORIZATION

int lcs(string x,string y,int n,int z,int m[][100]) 
{
	if(n==0 || z==0)
		return 0;
	
	else if(m[n][z]!=-1)
		return m[n][z];
	
	else{
	if(x[n-1]==y[z-1])
		return 1+lcs(x,y,n-1,z-1,m);
	else
		return max(lcs(x,y,n-1,z,m),lcs(x,y,n,z-1,m));
	}
	
}

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   int n,z;
   string X,Y;
   cin>>X>>Y;
   n=X.length();
   z=Y.length();
   int m[100][100];

   memset( m,-1,sizeof(m[0][0])*100*100  );
   cout<<lcs(X,Y,n,z,m);
   	 
}
*/

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
   
   for(i=1;i<=z;i++)
   {
	   for(j=1;j<=n;j++)
	   {
		if(X[i-1]==Y[j-1])
			dp[i][j]=1+dp[i-1][j-1];
		else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	   }
   }
   cout<<dp[z][n];
	
}






