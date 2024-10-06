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
void dfs(int i,int j,int m,int n,vector<vector<char>>&arr,vector<vector<int>>&vis){
    if(vis[i][j])return ;
    vis[i][j]=1;
    
    
    
        loop(k,0,8){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&x<m&&y>=0&&y<n&&arr[x][y]!='.'){
                dfs(x,y,m,n,arr,vis);
            }
        }
    
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
        int m,n;
        int t=1;int l;cin>>l;
        while(l--){
        cin>>n;m=n;
        vector<vector<char>>arr(m,vector<char>(n));
        vector<vector<int>>vis(m,vector<int>(n));
        loop(i,0,m){
            loop(j,0,n){
                cin>>arr[i][j];   
            }
        }int ans=0;
       loop(i,0,m){
            loop(j,0,n){
                if(arr[i][j]=='x'&&!vis[i][j]){
                    ans++;
                    dfs(i,j,m,n,arr,vis);
                }
            }
        }
     
        cout<<"Case "<<t++<<": "<<ans<<endl;}
        
        
        
    return 0;
}
