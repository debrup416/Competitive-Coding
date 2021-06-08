#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j,target;
	cout<<"Enter the number of coins\n";
	cin>>n;
	int coin[n+2];
	cout<<"Enter coins\n";
	for(i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	cout<<"Target Sum\n";
	cin>>target;
	int T[n+1][target+1];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=target;j++)
		{
			if(i==0)
				T[i][j]=INT_MAX-2;
			else if(i==1)
			{
				if(j%coin[0]==0)
					T[i][j]=j/coin[0];
				else
					T[i][j]=INT_MAX-2;		
			}
			else if(coin[i]<=j)
			{
				T[i][j]=min ( (1+T[i][j-coin[i-1]]) ,T[i-1][j] );
			}
			else
				T[i][j]=T[i-1][j];
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=target;j++)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<T[n][target];
}

