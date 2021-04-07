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
    sort(str.begin(),str.end());
    std::vector<string> v;
    v.push_back(str);
    while(next_permutation(str.begin(),str.end()))
    {
        v.push_back(str);
    }
    cout<<v.size()<<"\n";
    for(auto a:v)
        cout<<a<<"\n";
 
    
}




