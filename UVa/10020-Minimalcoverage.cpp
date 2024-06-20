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
        int m;cin>>m;
         int x,y;vector<pii>v,ans;
         while(1){
            cin>>x>>y;
            if(!x&&!y)break;
            if(x<m&&y>0)v.pb({x,y});
         }
         srt(v);
         int r=0;
         int i=0;int pos=1;
         while(i<v.size()){
            if(r>=m)break;
            if(r<v[i].first){pos=0;break;}
            int r2=0;int i2=-1;
             while(i<v.size()&&v[i].first<=r){
               if(v[i].second>r2){
                r2=v[i].second;
                i2=i;
               }
               i++;
             }
             if(i2>=0)ans.pb(v[i2]);      
             r=r2;
         }if(r<m)pos=0;
         if(!pos){cout<<0<<endl;}
         else{
            cout<<ans.size()<<endl;
            for(auto it:ans){
                cout<<it.first<<" "<<it.second<<endl;
            }
         }
         cout<<endl;
    }
    return 0;
}