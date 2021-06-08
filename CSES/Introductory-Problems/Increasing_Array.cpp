#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n,ans=0,m;
    cin>>n;
    std::vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        ll val;
        cin>>val;
        v.push_back(val);
    }
    m=v[0];
    for(ll i=1;i<n;i++)
    {
        if(m>v[i])
            ans+=(m-v[i]);
        m=max(m,v[i]);
    }
    cout<<ans;
 
}