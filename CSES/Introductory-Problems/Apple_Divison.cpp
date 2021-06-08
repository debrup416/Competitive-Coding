#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,i,j,c,val,sum,ans=INT_MAX;
    cin>>n;
    std::vector<ll> v;
    sum=0;
    for(i=0;i<n;i++)
    {
        cin>>val;
        sum+=val;
        v.push_back(val);
    }
    for(i=0;i<(1<<n);i++)
    {
        c=0;
        for(j=0;j<n;j++)
        {
            if((1<<j)&i)
                c+=v[j];
        }
        ans=min(ans,abs(sum-2*c));
    }
          cout<<ans;
    return 0;
 
}
 

