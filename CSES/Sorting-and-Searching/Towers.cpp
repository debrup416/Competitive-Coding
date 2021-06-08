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
    ll n,val;
    cin>>n;
    cin>>val;
    v.pb(val);
    for(ll i=1;i<n;i++)
    {
        cin>>val;
        ll index=lower_bound(v.begin(),v.end(),val+1)-v.begin();
        if(index==(ll)v.size())
            v.pb(val);
        else
            v[index]=val; 
       
    }
    cout<<v.size();
     
}
 



