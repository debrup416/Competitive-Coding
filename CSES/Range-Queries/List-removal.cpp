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
        segTree[index]=1;
        return ;
    }
 
    ll mid=(ss+se)/2;
    build(2*index,ss,mid);
    build(2*index+1,mid+1,se);
 
    segTree[index]=(segTree[2*index]+segTree[2*index+1]);
 
}
 
ll query(ll index, ll ss, ll se, ll val)
{ 
    
    if(ss==se){
        segTree[index]=0;
        return v[ss];
    }
 
    ll mid=(ss+se)/2;
    ll q1=0,q2=0;
    if(val<=segTree[2*index]){
        q1=query(2*index,ss,mid,val);
    }
    else{
        q2=query(2*index+1,mid+1,se,val-segTree[2*index]);
    }
    segTree[index]=segTree[2*index]+segTree[2*index+1];
    return max(q1,q2);
}
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,q,val;
    cin>>n;
    v.resize(n+1);
    segTree.resize(4*n+5);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    
    build(1,1,n);
    q=n;
    while(q--){
        cin>>val;
        cout<<query(1,1,n,val)<<" ";
    }
 
}
 
 
 
 
 
 



