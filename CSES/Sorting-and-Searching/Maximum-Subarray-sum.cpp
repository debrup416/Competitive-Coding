#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
 
#define test long long int T; cin>>T;  while(T--)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,val,sum=0,ans=INT_MIN;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        sum+=val;
        ans=max(ans,sum);
        if(sum<0)
            sum=0;
    }
    cout<<ans;
}






