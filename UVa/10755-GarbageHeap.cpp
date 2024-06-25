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
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
      int t;cin>>t;
      while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int sum[a][b][c];
        loop(i,0,a){loop(j,0,b)loop(k,0,c){
            cin>>sum[i][j][k];
            if(j>0)sum[i][j][k]+=sum[i][j-1][k];
            if(k>0)sum[i][j][k]+=sum[i][j][k-1];
            if(j>0&&k>0)sum[i][j][k]-=sum[i][j-1][k-1];
        }
      }int ans=INT64_MIN;
      loop(j1,0,b){
       loop(j2,0,c){
        loop(k1,j1,b){
            loop(k2,j2,c){int maxi=INT64_MIN;int s=0;
                loop(i,0,a){
                   int x=0;
                   x=sum[i][k1][k2];
                   if(j1>0)x-=sum[i][j1-1][k2];
                   if(j2>0)x-=sum[i][k1][j2-1];
                   if(j1>0&&j2>0)x+=sum[i][j1-1][j2-1];
                   s+=x;maxi=max(maxi,s);
                   if(s<0)s=0;
}ans=max(ans,maxi);
            }
        }
       }
      }cout<<ans<<endl;if(t)cout<<endl;
      }
	return 0;
}

