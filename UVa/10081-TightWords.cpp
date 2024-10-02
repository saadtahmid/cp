#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
// #define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007
double solve(int i,int len,int k,vector<vector<double>> &dp){   
    if(dp[i][len]!=-1){
        return dp[i][len];
    }
    double ans=0;
    if(i==0){
         loop(j,1,k+1){
               ans+=solve(j,len,k,dp);
         }
         return dp[i][len]=ans;
    }
    if(len==1){
        return 1;
    }
       ans+=solve(i,len-1,k,dp);
      if(i+1<=k) ans+=solve(i+1,len-1,k,dp);
      if(i>1) ans+=solve(i-1,len-1,k,dp);
    return dp[i][len]=ans;
}
signed main() {
   ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;
      cout.precision(5);
     int k,n;
     while(cin>>k>>n){vector<vector<double>>dp(11,vector<double>(101,-1));
         double ans=solve(0,n,k+1,dp);
         cout<<ans/pow(k+1,n)*100<<endl;
     }


    return 0;}