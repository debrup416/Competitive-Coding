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
    std::vector<ll>v ;
    map<ll,ll>mp;
    ll n,val,i,j=0,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        v.pb(val);
    }
    for(ll i=0,j=0;i<n;i++)
    {
        while(j<n && mp[v[j]]<1){
            mp[v[j]]++;
            j++;
        }
        ans=max(ans,(j-i));
        mp[v[i]]--;
    }
    cout<<ans;
}
 
