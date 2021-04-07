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
    for(ll k=1;k<=n;k++)
    {
        ll a=(k-4)*(k-4)*(k*k-9);
        ll b=4*(k*k-3);
        ll c=8*(k*k-4);
        ll d=4*(k-4)*(k*k-5);
        ll e=4*(k*k-5);
        ll f=4*(k-4)*(k*k-7);
        cout<<(a+b+c+d+e+f)/2<<"\n";
 
    }
     
 
}


