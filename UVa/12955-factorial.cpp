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
int solve(int i,int n,vector<vi>&dp,vi&factorials){
    if(i==9){
        if(n==0){
            return 0;
        }
        return 1e9;
    }
    if(dp[i][n]!=-1){
        return dp[i][n];
    }
    int take=1e9;
    if(n>=factorials[i]){
        take=solve(i,n-factorials[i],dp,factorials)+1;
    }
    int leave=solve(i+1,n,dp,factorials);
    return dp[i][n]=min(take,leave);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vi factorials(9);
    factorials[0] = 1;
    loop(i, 1, 9)
    {
        factorials[i] = factorials[i - 1] * i;
    }
    int n;
    while(cin>>n){
        vector<vi> dp(9,vi(n+1,-1));
        int ans=solve(1,n,dp,factorials);
        cout<<ans<<endl;
    }
    
    return 0;
}