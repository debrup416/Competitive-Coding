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
 
ll solve()
{
    ll n,high=0;
    cin>>n;
    std::vector<ll> v(n);
    for(ll i=0;i<n;i++){
        cin>>v[i];
        high=max(high,v[i]);
    }
    ll arr[high+1];
    memset(arr,0,sizeof(arr));
    for(ll i=0;i<n;i++)
        arr[v[i]]++;
    for(ll i=high;i>=1;i--)
    {
        ll j=i;
        ll c=0;
        while(j<=high){
            if(arr[j]>=2)
                return j;
            else if(arr[j]==1)
                c++;
 
            j+=i;
            if(c==2)
                return i;
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cout<<solve()<<"\n";
     
}
 




