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
int solve(int i,int mask,vector<vi>&dp,vector<vi>&dist){
    if(mask==(1<<(dp.size()))-1) return dist[i][0];
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=1e18;
    loop(j,1,dp.size()){
        if((mask&(1<<j))==0){
            ans=min(ans,dist[i][j]+solve(j,mask|(1<<j),dp,dist));
        }
    }
    return dp[i][mask]=ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        int startx,starty;
        cin >> n >> m >> startx >> starty;
        int k;cin >> k;
        vector<pii> v;
        v.pb({startx,starty});
        loop(i,0,k){
            int x,y;
            cin >> x >> y;
            v.pb({x,y});
        }
        vector<vi>dist(k+1,vi(k+1,1e18));
        loop(i,0,k+1){
            loop(j,0,k+1){
                if(i==j) dist[i][j] = 0;
                else{
                    int x1 = v[i].first;
                    int y1 = v[i].second;
                    int x2 = v[j].first;
                    int y2 = v[j].second;
                    dist[i][j] = abs(x1-x2) + abs(y1-y2);
                }
            }
        }
        vector<vi>dp(k+1,vi((1<<(k+1)),-1));
        int ans=solve(0,1,dp,dist);
        cout<<"The shortest path has length "<<ans<<endl;
        
    }
    return 0;}