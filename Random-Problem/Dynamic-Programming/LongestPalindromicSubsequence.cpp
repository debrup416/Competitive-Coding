#include<bits/stdc++.h>
using namespace std;

int main()
{
	 int x,y,i,j;
	 string str0,str1;
	 cin>>str0;
	 str1=str0;
	 reverse(str1.begin(),str1.end());
	 x=str1.length();
	 y=x;
	
	int dp[x+1][y+1];
	memset(dp,0,sizeof(dp));
	
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
		if(str0[i-1]==str1[j-1])
			dp[i][j]=1+dp[i-1][j-1];
		else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	cout<<"Longest Palindromic subsequence : "<<dp[x][y]<<"\n";
	cout<<"Minimum number of deletion to make Base string to palindrom :"<<x-dp[x][y];
}

 

