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
 
 
std::vector<ll> segTree,v;
 
void build(ll index,ll ss,ll se)
{
    if(ss==se){
        segTree[index]=v[ss];
        return ;
    }
 
    ll mid=(ss+se)/2;
    build(2*index,ss,mid);
    build(2*index+1,mid+1,se);
 
    segTree[index]=max(segTree[2*index],segTree[2*index+1]);
 
}
 
 
ll pointUpdate(ll index,ll ss, ll se, ll val)
{
 
    if(val>segTree[1]){
        return 0;
    }
    if(ss==se && segTree[index]>=val){
        segTree[index]-=val;
        return ss;
    }
 
    ll mid=(ss+se)/2;
    ll x;
    if(segTree[2*index]>=val)
         x=pointUpdate(2*index,ss,mid,val);
    else
         x=pointUpdate(2*index+1,mid+1,se,val);
    segTree[index]=max(segTree[2*index],segTree[2*index+1]);
    return x;
} 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q;
    cin>>n>>q;
    v.resize(n+1);
    segTree.resize(4*n+5);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    
    build(1,1,n);
 
    while(q--){
        ll val;
        cin>>val;
        cout<<pointUpdate(1,1,n,val)<<" ";
    }
 
}
 
 
 
 
 
 
 
 
 



