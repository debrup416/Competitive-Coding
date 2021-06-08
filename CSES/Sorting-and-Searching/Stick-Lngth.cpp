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
    ll n,val,op=0,me;
    std::vector<ll> v;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        v.pb(val);
    }
    sort(v.begin(),v.end());
    me=v[n/2];
    for(ll i=0;i<n;i++)
        op+=abs(me-v[i]);
    cout<<op;
}








