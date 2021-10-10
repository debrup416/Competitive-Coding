#include<bits/stdc++.h>
using namespace std;

int main()
{
	 
	int W,n,i,j;
	cout<<"Enter the number of element\n";
	cin>>n;
	int val[n+2],wt[n+2];
	cout<<"Enter the weights of every value\n";
	for(i=0;i<n;i++)
	{
			cin>>wt[i];
	}
	cout<<"Enter the value \n";
	for(i=0;i<n;i++)
	{
			cin>>val[i];
	}
	cout<<"Enter knapsack capacity\n";
	cin>>W;
	int table[n+1][W+1];
	 
	
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{		
			if(j==0 || i==0)
				table[i][j]=0;
			else if(wt[i-1]<=j)
			{
				table[i][j]=max( (val[i-1]+table[i-1][j-wt[i-1]]) ,table[i-1][j]);
			}
			else
			{
				table[i][j]=table[i-1][j];
			}
		}
	}
	
	/*for(i=0;i<=n;i++)
	{
		for(j=0;j<=W;j++)
		{
			cout<<table[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	
		 cout<<table[n][W];

	 return 0;
}