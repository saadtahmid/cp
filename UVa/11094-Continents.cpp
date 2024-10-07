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

int dfs(int i,int j,int m,int n,vector<vector<char>>&arr,vector<vector<int>>&vis,char c){
    if(vis[i][j])return 0;
    vis[i][j]=1;
    int ans=1;
    loop(k,0,4){
        int x=i+dx[k];
        int y=j+dy[k];
        y=(y+n)%n;
        if(x>=0 && x<m  && arr[x][y]==c){
            ans+=dfs(x,y,m,n,arr,vis,c);
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     // freopen("input.txt","r",stdin);
      //  freopen("output.txt","w",stdout);
      int m,n;
      while(cin>>m>>n){
        vector<vector<char>>arr(m,vector<char>(n));
        vector<vector<int>>vis(m,vector<int>(n,0));
        loop(i,0,m){
            loop(j,0,n){
                cin>>arr[i][j];
            }
        }
        int si,sj;
        cin>>si>>sj;
        char c=arr[si][sj];
        dfs(si,sj,m,n,arr,vis,c);
        int ans=0;
        loop(i,0,m){
            loop(j,0,n){
                if(arr[i][j]==c && !vis[i][j]){
                    ans=max(ans,dfs(i,j,m,n,arr,vis,c));
                }
            }
        } cout<<ans<<endl;  
      }
     
        
        
        
    return 0;
}
