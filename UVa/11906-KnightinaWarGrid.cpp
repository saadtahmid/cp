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
void dfs(int x, int y, int r, int c, vector<vi>&vis, vector<vi>&grid,vi&dx,vi&dy){
    if(vis[x][y]) return;
    vis[x][y]=1;
    int count=0;
    loop(i,0,dx.size()){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<r && ny>=0 && ny<c && grid[nx][ny]!=-1){
            count++;
            dfs(nx,ny,r,c,vis,grid,dx,dy);
        }
    }
    if(count==0) grid[x][y]=0;
    else if(count%2==0) grid[x][y]=2;
    else grid[x][y]=1;
}
void generateDirections(int m, int n, vector<int>& dx, vector<int>& dy) {
    int dx1[] = {m, m, -m, -m, n, n, -n, -n};
    int dy1[] = {n, -n, n, -n, m, -m, m, -m};
    
    set<pair<int, int>> directions;
    for (int i = 0; i < 8; i++) {
        directions.insert({dx1[i], dy1[i]});
    }
    for (const auto& dir : directions) {
        dx.push_back(dir.first);
        dy.push_back(dir.second);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l;cin>>l;
    loop(t,1,l+1){
       int r,c,m,n;
       
       
         cin>>r>>c>>m>>n;
            vector<int> dx, dy;
            generateDirections(m, n, dx, dy);
         vector<vi> vis(r,vi(c,0));
         
         vector<vi> grid(r,vi(c,0));
         int x;
            cin>>x;
            loop(i,0,x){
                int a,b;
                cin>>a>>b;
                grid[a][b]=-1;
            }
          dfs(0,0,r,c,vis,grid,dx,dy);
            int anse=0,anso=0;
            loop(i,0,r){
                loop(j,0,c){
                    if(grid[i][j]==2) anse++;
                    else if(grid[i][j]==1) anso++;
                }
            }
            if(anse==0 && anso==0) anse++;
       cout<<"Case "<<t<<": "<<anse<<" "<<anso<<endl;
    }
    return 0;
}

