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
    string str;
    cin>>str;
    ll n=str.length();
    ll arr[n+2];
    arr[0]=1;
    arr[1]=1;
    for(ll i=2;i<n+1;i++){
    	arr[i]=(i*arr[i-1])%mod;
    	arr[i]=arr[i]%mod;
    }
     
    ll cnt[27];
    memset(cnt,0,sizeof(cnt));
    for(ll i=0;i<str.length();i++)
    	cnt[str[i]-'a']++;
    ll ans=arr[n];
    for(ll i=0;i<26;i++){
    	ans*=inverse(arr[cnt[i]]);
    	ans%=mod;
    }
    cout<<ans;
 
 
 
     
    return 0; 
}
 





