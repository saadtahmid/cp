#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
int solve(int i,int n,int k,vector<int>&primes,vector<vector<vi>>&dp){
  if(n==0&&k==0){
    return 1;
  }
  if(n==0||k==0||i>=primes.size()){
    return 0;
  }
  if(dp[i][n][k]!=0){
    return dp[i][n][k];
  }
  int ans=0;
  ans+=solve(i+1,n,k,primes,dp);
  if(n-primes[i]>=0&&k-1>=0){
    ans+=solve(i+1,n-primes[i],k-1,primes,dp);
  }
  return dp[i][n][k]=ans;

}
signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  //make a sieve of eratosthenes to find all primes till 1120
    vector<int> primes;
    vector<bool> isprime(1121,true);    
    isprime[0]=isprime[1]=false;
    for(int i=2;i*i<=1120;i++){
      if(isprime[i]){
        for(int j=i*i;j<=1120;j+=i){
          isprime[j]=false;
        }
      }
    }   
    for(int i=2;i<=1120;i++){
      if(isprime[i]){
        primes.pb(i);
      }
    }
    
  int n,k;
  while(cin>>n>>k){
    if(n==0&&k==0){
      break;
    }
    vector<int>primes2;
    for(int i=0;i<primes.size();i++){
      if(primes[i]>n){
        break;
      }
      primes2.pb(primes[i]);
    }
    vector<vector<vi>>dp(primes2.size()+1,vector<vi>(n+1,vi(k+1,0)));
    //base case
    loop(i,0,primes2.size()+1){
      dp[i][0][0]=1;
    }
    //convert to tabulation
    for(int i=primes2.size()-1;i>=0;i--){
      loop(j,0,n+1){
        loop(l,0,k+1){
          dp[i][j][l]=dp[i+1][j][l];
          if(j-primes2[i]>=0&&l-1>=0){
            dp[i][j][l]+=dp[i+1][j-primes2[i]][l-1];
          }
        }
      }
    }
    int ans=dp[0][n][k];
   cout<<ans<<endl;
  };
  
  return 0;
}