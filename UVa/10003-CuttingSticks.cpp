#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(),x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007
int solve(int l,int r,vi &v,vector<vi>&dp){
    if(l+1==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1e18;
    loop(i,l+1,r){
        ans=min(ans,solve(l,i,v,dp)+solve(i,r,v,dp)+v[r]-v[l]);
    }
    return dp[l][r]=ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    while(cin>>t,t){
        int n;cin>>n;
        vi v;v.pb(0);
        loop(i,0,n){
            int x;cin>>x;
            v.pb(x);
        }
        v.pb(t);
        vector<vi>dp(n+2,vi(n+2,-1));
       int ans=solve(0,n+1,v,dp);
       cout<<"The minimum cutting is "<<ans<<"."<<endl;
    }
    return 0;}