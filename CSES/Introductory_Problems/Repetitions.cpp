#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    ll n=str.length(),i=0,j=0,c=0;
    while(j<n)
    {
        while(str[j]==str[i] && j<n)
            j++;
        c=max(c,(j-i));
        i=j;
    }
    cout<<c;
 
}
