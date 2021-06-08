#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,ans=0;
    cin>>n;
    
        for(ll i=5;i<=n;i=i*5)
            ans+=(n/i);
    
    cout<<ans;
 
}



