#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pi pair<ll,ll>
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
std::vector<std::vector<ll>> mat,iden,ans; 
 
void pnt(std::vector<std::vector<ll> > v)
{
	for(ll i=0;i<6;i++)
	{
		for(ll j=0;j<6;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
}
 
std::vector<std::vector<ll>> mul(vector<vector<ll>> mat1,vector<vector<ll>> mat2)
{
	std::vector<std::vector<ll> > res;
	ll val=0;
	for(ll i=0;i<6;i++)
	{
		std::vector<ll> temp;
		
		for(ll j=0;j<6;j++)
		{
			val=0;
			for(ll k=0;k<6;k++){
				val=((mat1[i][k]*mat2[k][j])%mod+val%mod)%mod;
			}
			temp.pb(val);
		}
		res.pb(temp);
	}
	return res;
}
 
std::vector<std::vector<ll>> midpow(std::vector<std::vector<ll>> v,ll n)
{
	while(n)
	{
		if(n&1)
			iden=mul(iden,mat);
		mat=mul(mat,mat);
		n/=2;
	}
	return iden;
}
 
 
int main()
{
	ll n;
	cin>>n;
	for(ll i=0;i<6;i++)
	{
		std::vector<ll> temp;
		for(ll j=0;j<6;j++)
		{
			if(i==j)
				temp.pb(1);
			else
				temp.pb(0);
		}
		iden.pb(temp);
		temp.clear();
	}
	for(ll i=0;i<6;i++)
	{
		std::vector<ll> temp;
		for(ll j=0;j<6;j++)
		{
			if(i==5)
				temp.pb(1);
			else if(i+1==j)
				temp.pb(1);
			else
				temp.pb(0);
		}
		mat.pb(temp);
		temp.clear();
	}
	ans=midpow(mat,n);
	cout<<ans[5][5];
	return 0;
	
}
 
 
 
 
 





