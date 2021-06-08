#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll; 
#define mod 1000000007
 
 
 
int main()
{
    static ll points[9999999]={0};
    points[0]=1;
    points[1]=1;
    ll N;
    cin>>N;
     
    for(ll i=2;i<=6;i++)
        points[i]=2*points[i-1];
    
    for(ll i=7;i<=N;i++){
        points[i]=points[i]%mod;
        points[i]=2*points[i-1]%mod-points[i-7]%mod;
        points[i]=points[i]%mod;
    }
    
    cout<<points[N]<<"\n";
 
    return 0;
}
 
 







