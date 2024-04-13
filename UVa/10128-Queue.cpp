#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
int dps(int n,int p,int r,vector<vector<vector<int>>>&dp){
    if(p==0||r==0||p>n||r>n||n==0)return dp[n][p][r]=0;
    if(n==1&&p==1&&r==1)return dp[n][p][r]=1;
    return dp[n][p][r]=dps(n-1,p-1,r,dp)+dps(n-1,p,r-1,dp)+dps(n-1,p,r,dp)*(n-2);
}
signed main(){
    int t;cin>>t;vector<vector<vector<int>>>dp(14,vector<vector<int>>(14,vector<int>(14,0)));
        //dps(n,p,r,dp)
        dp[1][1][1]=1;
        for(int N=2;N<=13;N++){
            for(int P=1;P<=N;P++){
                for(int R=1;R<=N;R++){
                    dp[N][P][R]=dp[N-1][P-1][R]+dp[N-1][P][R-1]+dp[N-1][P][R]*(N-2);
                }
            }
        }
    while(t--){
        int n,p,r;cin>>n>>p>>r;
        cout<<dp[n][p][r]<<'\n';

    }
    
    return 0;
}