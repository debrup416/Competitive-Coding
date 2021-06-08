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
 
 long long solve(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
   res=res%m;
    return res;
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
         ll a,b,c;
         cin>>a>>b>>c;
         ll ans1=solve(b,c,mod-1);
         cout<<solve(a,ans1,mod)<<"\n";
    }
      
}
 
 
 
 



