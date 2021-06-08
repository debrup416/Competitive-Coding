#include<bits/stdc++.h>
using namespace std;

int main()
{
	 int x,y,i,j;
	 string one,other;
	 cin>>one>>other;
	 x=one.length();
	 y=other.length();
	
	int dp[x+1][y+1];
	memset(dp,0,sizeof(dp));
	
	for(i=1;i<=x;i++)
	{
		for(j=1;j<=y;j++)
		{
		if(one[i-1]==other[j-1])
			dp[i][j]=1+dp[i-1][j-1];
		else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	
	int lcs=dp[x][y];
	cout<<"Deletion : "<<(x-lcs)<<"  Insertion : "<<(y-lcs);
}

 

