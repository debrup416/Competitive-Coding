#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    test{
        ll x,y;
        cin>>x>>y;
        ll edge,start,mid,end;
        edge=max(x,y);
        end=edge*edge;
        start=(edge-1)*(edge-1)+1;
        mid=(start+end)/2;
        if(edge&1)
        {
            cout<<mid+(y-x)<<"\n";
        }
        else
        {
            cout<<mid+(x-y)<<"\n";
        }
    }
     
 
}