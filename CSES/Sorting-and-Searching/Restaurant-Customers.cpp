#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
 
#define test long long int T; cin>>T;  while(T--)
 
#define pb push_back
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    
    set<pair<ll,ll>>s;
    ll n,ans=0,sum=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        s.insert({a,1});
        s.insert({b+1,-1});
    
    }
     
    for(auto x:s)
    {
        sum+=x.second;
        ans=max(sum,ans);
    }
    cout<<ans;
    return 0;
 
 
}


