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
   loop(k,0,t){
    int n,h,t1,t2;cin>>n>>h>>t1>>t2;
    vi v(n);
    loop(i,0,n)cin>>v[i];
    srt(v);
    int i=0;int j=n-1;int ans=0;
    while(i<=j){
        if(i==j){ans+=t1;break;}
        else{
         if(v[i]+v[j]<h&&t2<2*t1){
             i++;j--;
             ans+=t2;
         }else{
            j--;ans+=t1;
         }   
        }
    }
    cout<<"Case "<<k+1<<": "<<ans<<endl;
    
   }
    return 0;
}