#include<bits/stdc++.h>
#include<stdlib.h>
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
    int N;
    cin>>N;
    ll n=ceil(pow(2,N));
    for(ll i=0;i<n;i++){
    	ll val=(i^(i>>1));
    	std::string binary = std::bitset<16>(val).to_string();
    	binary=binary.substr(16-N);
    	cout<<binary<<"\n";
    	 
    }
     
    return 0; 
}
 



