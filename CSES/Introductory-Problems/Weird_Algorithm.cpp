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
    cout<<n<<" ";
    while(n!=1)
    {
        if(n&1)
            n=3*n+1;
        else
            n=n/2;
        cout<<n<<" ";
    }
    
     
}