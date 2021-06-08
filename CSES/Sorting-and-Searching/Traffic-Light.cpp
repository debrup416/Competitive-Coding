#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
 
int main() {
    
    ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,x;
  cin>>x>>n;
  multiset<ll> a,b;
  a.insert(0);
  a.insert(x);
  b.insert(x);
  for(ll i=0;i<n;i++)
  {
    ll k;
    cin>>k;
    auto it=a.upper_bound(k);
    auto it1=it;
    it1--;
    ll diff=*it-*it1;
    
    b.erase(b.find(diff));
    a.insert(k);
    b.insert(*it-k);
    b.insert(k-*it1);
    cout<<(*b.rbegin())<<" ";
  } 
	return 0;
}
 
 
 


