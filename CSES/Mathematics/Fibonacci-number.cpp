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
 
map<ll,ll>mp;
 
 
ll  fibo(ll n)
{
    if(mp[n]!=0)
        return mp[n];
    ll k=n/2;
    if(n%2==0)
        return mp[n]=(fibo(k)*fibo(k)+fibo(k-1)*fibo(k-1))%mod;
    else
         return mp[n]=(fibo(k)*fibo(k+1)+fibo(k-1)*fibo(k))%mod;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mp[0]=1;
    mp[1]=1;
    ll n;
    cin>>n;
    cout<<(n==0?0:fibo(n-1));
}






