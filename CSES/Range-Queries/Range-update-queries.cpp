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
 
 
std::vector<ll> segTree,v,lazy;
 
void build(ll index,ll ss,ll se)
{
    if(ss==se){
        segTree[index]=v[ss];
        return ;
    }
 
    ll mid=(ss+se)/2;
    build(2*index,ss,mid);
    build(2*index+1,mid+1,se);
 
    segTree[index]=(segTree[2*index]+segTree[2*index+1]);
 
}
 
ll query(ll index, ll ss, ll se, ll qs, ll qe)
{ 
    if(lazy[index]!=0){
        segTree[index]+=(se-ss+1)*lazy[index];
        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
     }
 
    if(qe<ss || qs>se)
        return 0;
    if(ss>=qs && se<=qe)
        return segTree[index];
 
    ll mid=(ss+se)/2;
    ll left=query(2*index,ss,mid,qs,qe);
    ll right=query(2*index+1,mid+1,se,qs,qe);
    return left+right;
 
}
 
// void pointUpdate(ll index,ll ss, ll se,ll qi)
// {
//     if(ss==se){
//         segTree[index]=v[ss];
//         return ;
//     }
 
//     ll mid=(ss+se)/2;
//     if(qi<=mid)
//         pointUpdate(2*index,ss,mid,qi);
//     else
//         pointUpdate(2*index+1,mid+1,se,qi);
//     segTree[index]=(segTree[2*index]+segTree[2*index+1]);
// }
 
void rangeUpdate(ll index,ll ss, ll se,ll qs , ll qe, ll val )
{
    if(lazy[index]!=0){
        segTree[index]+=(se-ss+1)*lazy[index];
        if(ss!=se){
            lazy[2*index]+=lazy[index];
            lazy[2*index+1]+=lazy[index];
        }
        lazy[index]=0;
    }
 
    if(ss>qe || se<qs)
        return ;
    if(ss>=qs && se<=qe){
        segTree[index]+=(se-ss+1)*val;
        if(ss!=se){
            lazy[2*index]+=val;
            lazy[2*index+1]+=val;
        }
        return ;
    }
    ll mid=(ss+se)/2;
    rangeUpdate(2*index,ss,mid,qs,qe,val);
    rangeUpdate(2*index+1,mid+1,se,qs,qe,val);
 
    segTree[index]=segTree[2*index]+segTree[2*index+1];
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
    lazy.resize(4*n+5);
    for(ll i=1;i<=n;i++){
        cin>>v[i];
    }
    
    build(1,1,n);
 
    // for(auto x:v)
    //     cout<<x<<" ";
    // cout<<"\n";
    // for(auto x:segTree)
    //     cout<<x<<" ";
 
    while(q--){
        ll ins,a,b,k,u;
        cin>>ins;
        if(ins==1){
            cin>>a>>b>>u;
            rangeUpdate(1,1,n,a,b,u);
        }
        else{
            cin>>k;
            cout<<query(1,1,n,k,k)<<"\n";
        }
    }
 
}
 
 
 
 
 
 


