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
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,res=1;
    cin>>n;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++)
        cin>>v[i];
    sort(v.begin(),v.end());
    for(ll i=0;i<n &&v[i]<=res;i++)
        res+=v[i];
    cout<<res;
}
 
 



