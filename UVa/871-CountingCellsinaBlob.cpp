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
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
int vis[35][35], cnt = 0;
int n;
char g[35][35];
int dfs(int i,int j){
    if(vis[i][j])return 0;
    vis[i][j]=1;
    int count=1;
    
    
        loop(k,0,8){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&x<n&&y>=0&&g[x][y]&&g[x][y]!='0'){
                count+=dfs(x,y);
            }
        }
    return count;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  //   freopen("input.txt","r",stdin);
     //   freopen("output.txt","w",stdout);
     int t;
    scanf("%d", &t);
    gets(g[0]);
    gets(g[0]);
    while(t--) {
        n = 0;
        memset(g,0, sizeof(g));
        while(gets(g[n])) {
            if(g[n][0] == '\0') break;
            n++;
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; g[i][j]; j++) {
                if(vis[i][j] == 0 && g[i][j] == '1') {
                    
                    ans=max(ans,dfs(i,j));
                    
                }
            }
        }
        printf("%d\n", ans);
        if(t)
            puts("");
    }
    return 0;
        
        
    return 0;
}
