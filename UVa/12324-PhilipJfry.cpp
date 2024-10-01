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
int n;int val[101];int wt[101];
int solve(int i,int used,vector<vi>&dp){
    if(i==n+1)return 0;
     if(dp[i][used]!=-1)return dp[i][used];
     int use=1e9;
     if(wt[i-1]>used)use=solve(i+1,used+1,dp)+(val[i]/2);
     int notused=solve(i+1,used,dp)+val[i];
     return dp[i][used]=min(use,notused);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin>>n,n){
       vector<vi>dp(n+1,vi(n+1,-1));
       loop(i,1,n+1)cin>>val[i]>>wt[i];
       loop(i,2,n+1){wt[i]+=wt[i-1];};
       int ans=val[1];
       ans+=solve(2,0,dp);
       cout<<ans<<endl;
    }
    return 0;
}