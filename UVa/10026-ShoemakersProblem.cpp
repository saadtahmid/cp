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
bool comp(pair<pii,int>a,pair<pii,int>b){
  if(a.first.first*b.first.second==b.first.first*a.first.second){
    return a.second<b.second;
  }  
  return a.first.first*b.first.second<b.first.first*a.first.second;
}
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<pii,int>>v;
        loop(i,0,n){
            int a,b;cin>>a>>b;
            v.pb({{a,b},i+1});
        }
        sort(v.begin(),v.end(),comp);
         loop(i,0,n){
         if(i)cout<<" ";   
        cout<<v[i].second;
    }cout<<endl;if(t)cout<<endl;
    }
   
    return 0;
}