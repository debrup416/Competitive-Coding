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
    int a,b;
    cin>>a>>b;
    int dp[a+1][b+1];
    for(int height=1;height<=a;height++)
    {
        for(int width=1;width<=b;width++)
        {
            if(height==width)
                dp[height][width]=0;
            else
            {
                int ans=1e8;
                for(int i=1;i<width;i++)
                    ans=min(ans,1+dp[height][i]+dp[height][width-i]);
                for(int i=1;i<height;i++)
                    ans=min(ans,1+dp[i][width]+dp[height-i][width]);
                dp[height][width]=ans;
            }
        }
    }
    
 
    cout<<dp[a][b];
    
}
 
 
 
 


