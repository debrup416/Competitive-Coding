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
  
// ll solve1()
// {
//     ll n;
//     cin>>n;
//     if(n&1)
//         return 0;
//     n=n/2;
//     ll dp[1000003];
//     dp[0]=1;
//     dp[1]=1;
//     for(ll i=2;i<=n;i++){
//         dp[i]=0;
//         for(ll j=0;j<i;j++)
//             dp[i]=((dp[j]*dp[i-j-1])%mod+dp[i]%mod)%mod;
//     }
//     return dp[n];
// }
 
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
 
ll solve2()
{
    ll n;
    ll res=1;
    cin>>n;
    if(n&1)
        return 0;
    n=n/2;
    //2nCn/(n+1)
    for(ll i=0;i<n;i++){
        res=(res*(2*n-i))%mod;
        res=(res*inverse(i+2))%mod;
       // cout<<" * "<<(2*n-i)<<" / "<<(i+1)<<" "<<res<<"\n";
    }
    return res;
}
 
ll solve()
{
    ll n;
    cin>>n;
    if(n&1)
        return 0;
    n/=2;
    ll dp[1000007];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1]=1;
    for(ll i=1;i<=2*n+2;i++)
    {
        dp[i]=(dp[i-1]%mod*i%mod)%mod;
    }
    ll ans=dp[2*n]%mod;
    ans=(ans*inverse(dp[n]))%mod;
    ans=(ans*inverse(dp[n+1]))%mod;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<solve();
    
    return 0; 
}
 





