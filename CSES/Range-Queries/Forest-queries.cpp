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
    cout.tie(0);
    ll n,q,i,j;
    cin>>n>>q;
    std::vector<ll> v(n+1,0);
    std::vector<std::vector<ll>> mat(n+1,v);
   
 
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                continue;
            char c;
            cin>>c;
            if(c=='*')
                mat[i][j]=1;
        }
    }
      
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mat[i][j]+=mat[i][j-1];
        }
    }
 
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            mat[i][j]+=mat[i-1][j];
        }
    }
 
       while(q--){
        ll y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        cout<<mat[y2][x2]-mat[y2][x1-1]-mat[y1-1][x2]+mat[y1-1][x1-1]<<"\n";
    }
}







