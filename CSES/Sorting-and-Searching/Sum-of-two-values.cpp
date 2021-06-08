#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll; 
#define mod 1000000007
#define fc(a,b) if(abs(a-b) < le-9)
#define pb push_back
 
int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	map<ll,ll>mp;
	ll n,x;
	cin>>n>>x;
	for(ll i=0;i<n;i++)
	{
		ll a;
		cin>>a;
		if(mp.find(x-a)!=mp.end())
		{
			cout<<mp[x-a]+1<<" "<<i+1;
			return 0;
		}
		mp[a]=i;
	}
	cout<<"IMPOSSIBLE";
 
	return 0;
}
 
