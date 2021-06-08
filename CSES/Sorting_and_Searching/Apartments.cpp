#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k,count=0 ,val,i,j=0;
    cin>>n>>m>>k;
    std::vector<ll> aplican;
    std::vector<ll> room;
    for(i=0;i<n;i++)
    {
        cin>>val;
        aplican.push_back(val);
    }
    for(i=0;i<m;i++)
    {
        cin>>val;
        room.push_back(val);
    }
    sort(room.begin(),room.end());
    sort(aplican.begin(),aplican.end());
    for(i=0,j=0;i<n;i++)
    {
        while(j<m && room[j]<aplican[i]-k)
            j++;
        if(j<m && room[j]<=aplican[i]+k)
            count++,j++;
    }
    cout<<count;
 
 
}
 
 
 
