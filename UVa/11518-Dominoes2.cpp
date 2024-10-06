#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
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
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int i,vector<vi>&adj,vi&vis){
    if(vis[i])return;
    vis[i]=1;
    for(auto x:adj[i]){
        dfs(x,adj,vis);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m,l;
        cin>>n>>m>>l;
        vector<vi>adj(n+1);vi vis(n+1,0);
        loop(i,0,m){
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
        }
        loop(i,0,l){
            int a;
            cin>>a;
            dfs(a,adj,vis);
        }int ans=0;
        loop(i,1,n+1){
            if(vis[i])ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

