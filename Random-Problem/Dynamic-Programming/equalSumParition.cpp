#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,j,target=0;
	cout<<"Enter the no of element in subset\n";
	cin>>n;
	int s[n];
	cout<<"Enter the number\n";
	for(i=0;i<n;i++)
	{
		 cin>>s[i];
		 target+=s[i];
	}
	if(target&1)
		{
			cout<<"Not Possible";
			return 0;
		}
	else
		target/=2;
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
				T[i][j]=(T[i-1][j-s[i-1]] || T[i-1][j]);
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
	if(T[n][target])
		cout<<"possible";
	else
		cout<<"Not Possible";
		
}

