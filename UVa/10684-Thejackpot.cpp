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
      int n;
      while(cin>>n,n){
        vi v(n);loop(i,0,n)cin>>v[i];
        int ans =-1e9;int sum=0;
        loop(i,0,n){
           sum+=v[i];
           if(sum<0)sum=0;
           ans=max(ans,sum);
        }
        if(ans>0){cout<<"The maximum winning streak is "<<ans<<".\n";}
        else cout<<"Losing streak.\n";
      }
	return 0;
}