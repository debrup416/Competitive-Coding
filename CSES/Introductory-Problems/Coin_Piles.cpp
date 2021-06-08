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
    test{
        ll a,b;
        cin>>a>>b;
        if(a==0 && b==0)
            cout<<"YES\n";
        else if(a==0 || b==0)
            cout<<"NO\n";
        else if(abs(a-b)>min(a,b))
            cout<<"NO\n";
        else if((a+b)%3==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
 
}


