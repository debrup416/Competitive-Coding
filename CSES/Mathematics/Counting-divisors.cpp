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
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll arr[1000007];
    memset(arr,0,sizeof(arr));
    for(ll i=1;i<1000007;i++)
    {
        for(ll j=i;j<1000007;j+=i)
        {
            arr[j]++;
        }
    }
    test{
        ll n;
        cin>>n;
        cout<<arr[n]<<"\n";
    }
    
     
    return 0; 
}
 




