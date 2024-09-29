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
int n;
int solve(int u,int mask,vector<vi>&dp,vi &reachable){
    if(mask==(1<<(n+1))-1){
        return 1;
    }
    if(dp[u][mask]!=-1){
        return dp[u][mask];
    }
    int ans=0;
    loop(i,1,n+1){
        //check if visited or not and if reachable from u (0 means not visited)
        if(!(mask&(1<<i))&&((reachable[mask]>>(n-i))&1)){
            ans+=solve(i,mask|(1<<i),dp,reachable);         
        }
    }
    return dp[u][mask]=ans;
    
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;cin>>x;
    
    loop(t,1,x+1){
        cin>>n;vi reach;
        loop(i,0,n+1){
            string s;cin>>s;
            int a = stoi(s, 0, 2);
            reach.pb(a);
        }
    vi reachable(1<<(n+1), 0);
    reachable[1]=reach[0];
    loop(i,1,1<<n){
        reachable[(i<<1)|1]=reach[0];
        loop(j,0,n){
            if(i&(1<<j)){
                reachable[(i<<1)|1]|=reach[j+1];
            }
        }
    } 
        //mask is the set of visited nodes where 1 means visited and 0 means not visited it is indexed from right to left
        //dp[u][mask] is the number of ways to visit all the nodes starting from u and visiting all the nodes in mask
        //reachable[mask] is the set of nodes that can be visited from the nodes in mask it is indexed from left to right
        vector<vi>dp((n+1),vi(1<<(n+1),-1));

        int ans=solve(0,1,dp,reachable);
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
   
    return 0;}