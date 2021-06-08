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
    ll n,i;
    cin>>n;
    std::vector<ll>v(n),dp;
    for(i=0;i<n;i++)
        cin>>v[i];
   // dp.resize(n,1);
    dp.pb(v[0]);
    for(i=1;i<n;i++)
    {
        if(dp[dp.size()-1]<v[i])
            dp.pb(v[i]);
        else if(dp[dp.size()-1]>v[i]){
            ll it=(lower_bound(dp.begin(),dp.end(),v[i])-dp.begin());
            dp[it]=v[i];
            //cout<<"---"<<it<<"---\n";
        }
         
    }
    /*for(auto x:dp)
        cout<<x<<" ";
        */
    cout<<dp.size();
 
}
 
 
 


