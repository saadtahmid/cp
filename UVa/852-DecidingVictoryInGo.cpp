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

void dfs(int i,int j,int m,int n,vector<vector<char>>&arr,vector<vector<int>>&vis,char c1,char c2){
    if(vis[i][j])return ;
    vis[i][j]=1;
    
    loop(k,0,4){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0 && x<m  && y>=0&&y<n&&arr[x][y]!=c2){
            dfs(x,y,m,n,arr,vis,c1,c2);
        }
    }
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     // freopen("input.txt","r",stdin);
      //  freopen("output.txt","w",stdout);
      int t; cin>>t;
      while(t--){
          vector<vector<char>>grid(9,vector<char>(9));
          vector<vector<int>>visw(9,vector<int>(9,0));
          vector<vector<int>>visb(9,vector<int>(9,0));
           
          loop(i,0,9){
              loop(j,0,9){
                  cin>>grid[i][j];
              }
          }
         int w=0,b=0;
         loop(i,0,9){
             loop(j,0,9){
                 if(grid[i][j]=='O' && !visw[i][j]){
                     dfs(i,j,9,9,grid,visw,'O','X');
                     
                 }
                 if(grid[i][j]=='X' && !visb[i][j]){
                     dfs(i,j,9,9,grid,visb,'X','O');
                    
                 }
             }
         }
            loop(i,0,9){
                loop(j,0,9){
                    if(visw[i][j] && !visb[i][j])w++;
                    if(visb[i][j] && !visw[i][j])b++;
                }
            }
            cout<<"Black "<<b<<" White "<<w<<endl;
      }
      
        
        
        
    return 0;
}
