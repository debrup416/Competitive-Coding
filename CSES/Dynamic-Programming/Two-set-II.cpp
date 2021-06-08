// #include<bits/stdc++.h>
// using namespace std;
 
// typedef long long int  ll;
// #define mod 1000000007
// #define test long long int T; cin>>T;  while(T--)
// #define fc(da,db) if(abs(da-db) < le-9)
// #define pi pair<ll,ll>
// #define pb push_back
// #define mk make_pair
// #define eb emplace_back
 
// /*ll dp[5001][5001];
// ll solve(std::vector<ll> &v,int i,int j)
// {
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     if(i==j)
//         return v[i];
//     if(i+1==j)
//         return max(v[i],v[j]);
//     ll val=max(v[i]+min(solve(v,i+2,j),solve(v,i+1,j-1)),v[j]+min(solve(v,i+1,j-1),solve(v,i,j-2)));
    
//     return dp[i][j]=val;
// }*/
 
 
// int solve1(int n,int curr,int target)
// {
     
//     if(curr==target)
//         return 1;
//     if(n<=0)
//         return 0;
//     return solve1(n-1,curr,target)+solve1(n-1,curr+n,target);
    
    
// }
 
// int solve(int n,int curr)
// {
//     if(curr==0)
//         return 1;
//     if(n==0)
//         return 0;
//     return solve(n-1,curr)+solve(n-1,curr-n);
// }
 
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int n,target;
//     cin>>n;
//     target=n*(n+1)/2;
//     if(target&1)
//         cout<<0;
//     else{
//         target=target/2;
//        //cout<<solve1(n,0,target)/2;
//         cout<<solve(n,target)/2;
//     }
     
    
// }
 
// void solve2()
// {
//     ll n,target;
//     cin>>n;
//     target=n*(n+1)/2;
//     if(target&1){
//         cout<<0<<"\n";
//     }
//     else{
//     target=target/2;
//     ll dp[n+1][target+1];
//     for(int i=0;i<=target;i++)
//         dp[0][i]=0;
//     for(int i=0;i<=n;i++)
//         dp[i][0]=1;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=target;j++)
//         {
//             if(i>j)
//                 dp[i][j]=dp[i][j]%mod;
//             else
//                  dp[i][j]=(dp[i-1][j]%mod+dp[i-1][j-i]%mod)%mod;
               
 
//         }
//     }
//     cout<<(dp[n-1][target]*500000004)%mod;
// }
//     return ;
// }
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     solve2();
// }
 
 
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;
 
  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
    (dp[i][j] += dp[i-1][left]) %= mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}





















