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
 
 ll _binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
 
ll inverse(ll a)
{
	return _binpow(a,mod-2,mod);
} 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll d[n+2];
    d[1]=0;
    d[2]=1;
    for(ll i=3;i<=n;i++){
    	d[i]=((d[i-1]+d[i-2])%mod*(i-1))%mod;
    }
    cout<<d[n];
 
 
 
     
    return 0; 
}
 









