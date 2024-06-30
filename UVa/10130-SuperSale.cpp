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
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(),x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
int solve(int i,int n,int remw,vi &p,vi&w,vector<vi>&dp){
       if(i==n||remw==0)return dp[i][remw]=0;
	   if(dp[i][remw]!=-1)return dp[i][remw];
	   if(w[i]>remw)return dp[i][remw]=solve(i+1,n,remw,p,w,dp);
	   return dp[i][remw]=max(solve(i+1,n,remw,p,w,dp),p[i]+solve(i+1,n,remw-w[i],p,w,dp));
}
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
	int n;cin>>n;
	vi p(n),w(n);
	loop(i,0,n){
		cin>>p[i];
		cin>>w[i];
	}
	int g;cin>>g;int ans=0;
	loop(i,0,g){
		int a;cin>>a;
		vi curr(a+1,-1),next(a+1,0);
		for(int i=n-1;i>=0;i--){
			curr[0]=0;
			loop(remw,1,a+1){
               if(w[i]>remw)curr[remw]=next[remw];
	            else curr[remw]=max(next[remw],p[i]+next[remw-w[i]]);
			}
			next=curr;
		}
        ans+=curr[a];
	}cout<<ans<<endl;
  }
	
	return 0;
}