#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
#define pb push_back
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,val;
    cin>>n>>m;
    set<pair<ll,ll>>s;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        s.insert({val,i});
    }     
    for(ll i=0;i<m;i++)
    {
        cin>>val;
        auto it=s.lower_bound({val+1,0});
        if(it==s.begin())
            cout<<-1<<"\n";
        else
        {
            --it;
            cout<<it->first<<"\n";
            s.erase(it);
        }
    }
    return 0;
 
}
