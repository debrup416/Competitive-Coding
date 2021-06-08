#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
ll solve()
{
    ll n;
    cin>>n;
   std::vector<ll> v;
   for(ll i=0;i<n-1;i++)
   {
    ll val;
    cin>>val;
    v.push_back(val);
   }
   sort(v.begin(),v.end());
   for(ll i=0;i<n-1;i++)
   {
    if(v[i]!=i+1)
        return 1+i;
   }
   return n;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout<<solve();
    
     
}