#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    if(n%4==0)
    {
        cout<<"YES\n";
        cout<<n/2<<"\n";
        for(ll i=1;i<=n/2;i+=2)
            cout<<i<<" "<<(n+1-i)<<" ";
        cout<<"\n";
        cout<<n/2<<"\n";
        for(ll i=2;i<=n/2;i+=2)
            cout<<i<<" "<<(n+1-i)<<" ";
    }
    else if((n+1)%4==0)
    {
        cout<<"YES\n";
        cout<<n/2+1<<"\n";
        cout<<1<<" "<<2<<" ";
        for(ll i=4;i<=n/2+1;i+=2)
            cout<<i<<" "<<(n+4-i)<<" ";
        cout<<"\n";
        cout<<n/2<<"\n";
        cout<<3<<" ";
        for(ll i=5;i<=n/2+2;i+=2)
            cout<<i<<" "<<(n+4-i)<<" ";
 
    }
    else
        cout<<"NO\n";
 
}






