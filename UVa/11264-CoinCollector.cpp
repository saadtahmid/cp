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
    int t
;cin>>t;
while(t--){
    int n;cin>>n;vi v(n);int sum=1;int cnt=1;
    loop(i,0,n){cin>>v[i];}
    loop(i,1,n-1){
      if(sum+v[i]<v[i+1]){
        cnt++;sum+=v[i];
      }
    }
    if(n==1)cout<<1<<endl;
    else cout<<cnt+1<<endl;
   
}
    return 0;
}