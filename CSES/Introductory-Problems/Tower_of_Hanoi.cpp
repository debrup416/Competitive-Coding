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
 
 
 
void toH(ll n, int from, int to, int aux)
{
	if(n==1){
		cout<<from<<" "<<to<<"\n";
		return ;
	}
	toH(n-1,from,aux,to);
	cout<<from<<" "<<to<<"\n";
	toH(n-1,aux,to,from);
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    cout<<ceil(pow(2,n))-1<<"\n";
    toH(n,1,3,2);
    return 0; 
}
 


