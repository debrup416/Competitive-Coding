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
 
int solve(ll num)
{
    int high=0,res;
    while(num)
    {
        res=num%10;
        high=max(high,res);
        num/=10;
    }
    return high;
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,c=0;
    cin>>n;
    while(n>0)
    {
        //cout<<n<<" ";
        int findmax=solve(n);
        //cout<<findmax<<"\n";
        n-=findmax;
        c++;
    }
    cout<<c<<"\n";
    
 
}
 
 



