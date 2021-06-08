#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
 
#define test long long int T; cin>>T;  while(T--)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    ll n,ans=0,e=0;
    cin>>n;
    std::vector<pair<ll,ll>> v;
    for(ll i=0;i<n;i++)
    {
        ll strt,end;
        cin>>strt>>end;
        v.emplace_back(make_pair(end,strt));
    }
    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++)
    {
 
        if(v[i].second>=e){
               ++ans;
              e=v[i].first;
 
        }
           
    }
    cout<<ans;
 
}
