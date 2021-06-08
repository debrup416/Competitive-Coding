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
    if(n==3 ||n==2)
        cout<<"NO SOLUTION";
    else
    {
        for(ll i=2;i<=n;i+=2)
            cout<<i<<" ";
        for(ll i=1;i<=n;i+=2)
            cout<<i<<" ";
    }
 
}