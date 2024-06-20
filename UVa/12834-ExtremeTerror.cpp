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
    int t;cin>>t;loop(j,0,t){
        int n,k;cin>>n>>k;
        vi v(n);
        loop(i,0,n)cin>>v[i];
        loop(i,0,n){
            int x;cin>>x;
            v[i]=x-v[i];
        }
        srt(v);
        int ans=0;
        loop(i,0,n){
            if(v[i]<0&&k){k--;continue;
            }else{ans+=v[i];
            }
        }
        cout<<"Case "<<j+1<<": ";
        if(ans<=0)cout<<"No Profit"<<endl;else cout<<ans<<endl;
            }
    return 0;
}