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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
signed main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);int n,m;
	while(cin>>n>>m){
        if(n==0&&m==0)break;
        vector<int>pos;for(int i=0;i<n;i++)pos.pb(i);int ans=0;
        vector<vector<int>>cons;
        for(int i=0;i<m;i++){
            int a,b,c;cin>>a>>b>>c;
            cons.pb({a,b,c});
        }
        do{int ok=1;
            for(int i=0;i<m;i++){
                int _a;
           int _b;
           for(int j=0;j<n;j++){
                if(pos[j]==cons[i][0])_a=j;
                if(pos[j]==cons[i][1])_b=j;
           }
           if(cons[i][2]<0){
            if(abs(_b-_a)<-cons[i][2])ok=0;
           }else{
             if(abs(_b-_a)>cons[i][2])ok=0; 
           }
            }
           if(ok)ans++;

        }while(next_permutation(pos.begin(),pos.end()));
        cout<<ans<<endl;
    }
	return 0;
}
