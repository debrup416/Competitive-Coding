#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(da,db) if(abs(da-db) < le-9)
#define pb push_back
#define mk make_pair
#define eb emplace_back
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string target;
    cin>>target;
    ll m=target.length();
    std::vector<ll> pi(m);
    pi[0]=0;
    for(ll i=1;i<m;i++){
        ll j=pi[i-1];
        while(j>0 && target[i]!=target[j])
            j=pi[j-1];
        if(target[i]==target[j])
            j++;
        pi[i]=j;
    }
    ll maxi=pi[m-1];
    std::vector<ll> ans;
    while(maxi>0){
        ans.pb(maxi);
        maxi=pi[maxi-1];
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans)
        cout<<x<<" ";
  
    return 0; 
}
 
 
 
 
 
 
 


