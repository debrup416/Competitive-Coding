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
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    std::vector<ll> v;
    ll sum=0,val;
    v.pb(0);
    for(ll i=0;i<n;i++){
        cin>>val;
        sum+=val;
        v.pb(sum);
    }
    while(q--){
        ll a,b;
        cin>>a>>b;
        cout<<v[b]-v[a-1]<<"\n";
    }
}





