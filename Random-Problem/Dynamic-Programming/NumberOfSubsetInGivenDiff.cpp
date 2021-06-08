#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j,sum=0,target,diff;
	cout<<"Enter the no of element in subset\n";
	cin>>n;
	int s[n+2];
	cout<<"Enter the number\n";
	for(i=0;i<n;i++)
	{
		 cin>>s[i];
		 sum+=s[i];
	}
	cout<<"Enter Difference between 2 subset\n";
	cin>>diff;
	target=(sum-diff)/2;
	int T[n+1][target+1];
	memset(T,0,sizeof(T));
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=target;j++)
		{
			if(s[i-1]<=j)
			{
				T[i][j]=(T[i-1][j-s[i-1]] + T[i-1][j]);
			}
			else
			{
				T[i][j]=T[i-1][j];
			}
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
	cout<<T[n][target];
		
}

