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
#define endl "\n"
void solve(int ind,vector<vector<char>>&mat,vector<int>&row,vector<int>&col,int cnt,int &ans){
     if(ind==row.size()*col.size()){ans=max(ans,cnt);return;}
	 if(mat[ind/row.size()][ind%row.size()]=='X'){row[ind/row.size()]=0;col[ind%row.size()]=0;
	 solve(ind+1,mat,row,col,cnt,ans);}
	 else{
        solve(ind+1,mat,row,col,cnt,ans);
		if(!row[ind/row.size()]&&!col[ind%row.size()]){
			row[ind/row.size()]=1;col[ind%row.size()]=1;
			solve(ind+1,mat,row,col,cnt+1,ans);
			row[ind/row.size()]=0;col[ind%row.size()]=0;
		}
	 }
     
}
signed main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n){
		if(n==0)break;
		vector<vector<char>> mat(n,vector<char>(n));vector<int>row(n,0),col(n,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)cin>>mat[i][j];	
		}
		int ans=0;
		solve(0,mat,row,col,0,ans);
		cout<<ans<<endl;
		}
	    
	return 0;
}
