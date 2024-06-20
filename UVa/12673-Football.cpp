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
    int n,g;while(cin>>n>>g){
        vi v(n);
     loop(i,0,n){
       int a,b;cin>>a>>b;
       v[i]=b-a;
     }
     srt(v);int ans=0;
     loop(i,0,n){
        if(v[i]<0){ans+=3;continue;}
        if(g&&g>=v[i]){
            if(g>v[i]){
                g-=v[i]+1;ans+=3;
            }else{
                g=0;ans++;
            }
        }else if(v[i]==0){
            ans++;
        }
     }
     cout<<ans<<endl;
    }
    return 0;
}