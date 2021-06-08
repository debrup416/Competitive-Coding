#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mx 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,val;
    cin>>n;
    std::vector<ll> v;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    cout<<distance(v.begin(),unique(v.begin(),v.end()));
     
 
}