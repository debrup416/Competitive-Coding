#include<bits/stdc++.h>
using namespace std;
 
typedef long long int  ll;
#define mod 1000000007
#define test long long int T; cin>>T;  while(T--)
#define fc(a,b) if(abs(a-b) < le-9)
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin>>str;
    ll a[30],s=str.length();
    int one=0,index=-1;
    memset(a,0,sizeof(a));
    for(ll i=0;i<s;i++)
    {
        int val=str[i]-'A';
        a[val]++;
    }
    for(ll i=0;i<26;i++)
    {
        if(a[i]&1){
            one++;
            index=i;
        }
         
            a[i]/=2;
    }
    if(one>1)
        cout<<"NO SOLUTION\n";
    else
    {
        str="";
        for(ll i=0;i<26;i++)
        {
            while(a[i]>0)
            {
                str+=(char)(i+'A');
                a[i]--;
            }
        }
        cout<<str;
        if(one==1)
            cout<<(char)(index+'A');
        reverse(str.begin(),str.end());
        cout<<str;
 
    }
 
    
}






