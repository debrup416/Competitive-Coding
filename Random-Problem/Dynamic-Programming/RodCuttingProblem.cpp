#include<bits/stdc++.h>
using namespace std;

int main()
{
	int  len,i,j;
	cout<<"Enter the length of rod\n";
	cin>>len;
	int lnth[len+2],price[len+2];
	cout<<"Enter the price\n";
	for(i=0;i<len;i++)
	{
		cin>>price[i];
		lnth[i]=i+1;
	}
	int T[len+1][len+1];
	memset(T,0,sizeof(T));
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len;j++)
		{
			if(lnth[i-1]<=j)
			{
				T[i][j]=max(T[i-1][j],(T[i][j-lnth[i-1]]+price[i-1]));
			}
			else
				T[i][j]=T[i-1][j];
		}
	}
	for(i=0;i<=len;i++)
	{
		for(j=0;j<=len;j++)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Max Profit  "<<T[len][len];
}

