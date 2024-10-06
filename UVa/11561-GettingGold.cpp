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
int dfs(int i,int j,int m,int n,vector<vector<char>>&arr,vector<vector<int>>&vis){
    if(vis[i][j])return 0;
    vis[i][j]=1;
    int count=0;
    if(arr[i][j]=='G')count++;
    bool ok=1;
    loop(k,0,4){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x>=0&&x<m&&y>=0&&y<n&&arr[x][y]=='T'){
            ok=0;
        }
    }
    if(ok){
        loop(k,0,4){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0&&x<m&&y>=0&&y<n&&arr[x][y]!='#'){
                count+=dfs(x,y,m,n,arr,vis);
            }
        }
    }
    return count;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
        int m,n;

        while(cin>>n>>m){
        vector<vector<char>>arr(m,vector<char>(n));
        vector<vector<int>>vis(m,vector<int>(n));
        int starti,startj;
        loop(i,0,m){
            loop(j,0,n){
                cin>>arr[i][j];
                if(arr[i][j]=='P'){
                    starti=i;
                    startj=j;
                }
            }
        }int ans=0;
        ans=dfs(starti,startj,m,n,arr,vis);
     
        cout<<ans<<endl;}
        
        
    return 0;
}
