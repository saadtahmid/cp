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
int solve(int l,int s,int i,vector<vector<vi>>&dp){
    if(l==0&&s==0)return 1;
    if(l==0||s==0||i>26)return 0;
    if(dp[l][s][i]!=-1)return dp[l][s][i];
    int ans=0;
    if(s-i>=0)ans+=solve(l-1,s-i,i+1,dp);
    ans+=solve(l,s,i+1,dp);
    return dp[l][s][i]=ans;
   
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int l,s;int c=1;
    while(1){
        cin>>l>>s;
        if(l==0&&s==0)break;
        if(l>26||s>351){
            cout<<"Case "<<c++<<": "<<0<<endl;
            continue;
        }
        vector<vector<vi>>dp(27,vector<vi>(352,vi(27,-1)));
        int ans=solve(l,s,1,dp);
        cout<<"Case "<<c++<<": "<<ans<<endl;
    }
    return 0;}