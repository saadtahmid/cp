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
  int n,p;
  while(cin>>n>>p){
    pq<pii> maxi;
    vi hash(p);vi init(p);
    loop(i,0,p){
     int x;cin>>x;
     maxi.push({x,i});
     hash[i]=1;
     init[i]=x;
    }
    loop(i,0,n-p){
        auto a=maxi.top();maxi.pop();
        maxi.push({(init[a.second]+hash[a.second])/(hash[a.second]+1),a.second});
        hash[a.second]++;
    }
    cout<<maxi.top().first<<endl;
  }
    return 0;
}