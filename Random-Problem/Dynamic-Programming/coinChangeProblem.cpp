#include<bits/stdc++.h>
using namespace std;

int main()
{
	int  n,i,j,target;
	cout<<"Enter the number of coin\n";
	cin>>n;
	int coin[n+2];
	cout<<"Enter the coin array\n";
	for(i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	cout<<"Enter the target \n";
	cin>>target;
	int T[n+1][target+1];
	memset(T,0,sizeof(T));
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=target;j++)
		{
			if(coin[i-1]<=j)
			{
				T[i][j]=(T[i-1][j] + T[i][j-coin[i-1]] );
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
		cout<<endl;
	}
	cout<<"Max Profit  "<<T[n][target];
}

