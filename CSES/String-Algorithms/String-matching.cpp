#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str,target;
    cin>>str>>target;
    target+="#";
    ll n=str.length(),m=target.length();
    std::vector<ll> pi(m);
    pi[0]=0;
    for(ll i=1;i<m;i++){
        ll j=pi[i-1];
        while(j>0 && target[i]!=target[j])
            j=pi[j-1];
        if(target[i]==target[j])
            j++;
        pi[i]=j;
    }
    m--;
    ll l,count=0,prev=0;
    for(ll i=0;i<n;i++){
        l=prev;
        while(l>0 && str[i]!=target[l])
            l=pi[l-1];
        if(str[i]==target[l])
            l++;
        prev=l;
        if(l==m)
            count++;
    }
    cout<<count;
     
    return 0; 
}
 
 
 
 
// #include<bits/stdc++.h>
// using namespace std;
 
// typedef long long int  ll;
// #define mod 1000000007
// #define test long long int T; cin>>T;  while(T--)
// #define fc(da,db) if(abs(da-db) < le-9)
// #define pi pair<ll,ll>
// #define pb push_back
// #define mk make_pair
// #define eb emplace_back
 
// ll inv[1000004];
// ll dp[1000004];
 
//  ll _binpow(ll a, ll b, ll m) {
//     a %= m;
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a % m;
//         a = a * a % m;
//         b >>= 1;
//     }
//     return res;
// }
 
// ll init(string str)
// {
//     ll p=31;
//     ll p_power=1;
//     inv[0]=1;
//     dp[0]=(str[0]-'a'+1);
//     for(ll i=1;i<str.length();i++)
//     {
//         char ch=str[i];
//         p_power=(p*p_power)%mod;
//         inv[i]=_binpow(p_power,mod-2,mod);
//         inv[i]=inv[i]%mod;
//         dp[i]=(dp[i-1]+(ch-'a'+1)*p_power)%mod;
//     }
//     return dp[str.length()-1];
// }
 
// ll hash1(ll left, ll right)
// {
//    // ll res=dp[right];
//     ll res;
//     if(left>0)
//         res=(dp[right]-dp[left-1]+mod)%mod;
//     else
//         res=(dp[right])%mod;
//     res=(res*inv[left])%mod;
//     return res;
// }
 
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     string str,target;
//     cin>>str>>target;
//     ll count=0;
//     ll n=str.length();
//     ll m=target.length();
 
//     ll match=init(target);
//     memset(dp,0,sizeof(dp));
//     init(str);
//   //  cout<<match<<"\n";
  
//     for(ll i=0;i+m<=n;i++){
//         // for(ll k=i;k<i+m;k++)
//         //     cout<<str[k];
//         // cout<<" : ";
//         // cout<<hash1(i,i+m-1)<<"\n ";
//         if((hash1(i,i+m-1)==match)){
//             count++;
//         }
//     }
//     cout<<count;
 
     
//     return 0; 
// }
 
 
 
 
 