 #include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j,sum;
	cout<<"Enter the no of element in subset\n";
	cin>>n;
	int s[n+2];
	cout<<"Enter the number\n";
	for(i=0;i<n;i++)
	{
		 cin>>s[i];
	}
	cout<<"Enter Target\n";
	cin>>sum;
	int T[n+1][sum+1];
	memset(T,0,sizeof(T));
	for(i=0;i<=n;i++)
		T[i][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=sum;j++)
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
		for(j=0;j<=sum;j++)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<T[n][sum];
		
}

