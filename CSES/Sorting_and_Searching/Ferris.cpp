#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,x,val,i,j,ans=0;
    cin>>n>>x;
    std::vector<ll> v;
    for(i=0;i<n;i++)
    {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end(),greater<ll>());
    j=n-1;
    i=0;
    while(i<=j)
    {
        if(v[i]+v[j]<=x)
        {
            ans++;
            i++;
            j--;
        }
        else
        {
            ans++;
            i++;
        }
        
    }
    cout<<ans;
}
 
 


