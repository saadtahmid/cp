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
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		int s,f;vector<int>meets;
		while(1){
			cin>>s>>f;
			if(s==0&&f==0)break;
			int mask=~0;
			mask=mask<<(f-s);mask=~mask;
			mask=mask<<s;
            meets.pb(mask);
		}int ans=0;
	   for(int i=1;i<=(1<<meets.size())-1;i++){int cnt=0;int common=0;int match=0;
		for(int j=0;j<meets.size();j++){
			if(i&(1<<j)){
              common=match&meets[j];
              if(common)break;
			  match=match|meets[j];
			  cnt++;
			}
		}if(!common)ans=max(cnt,ans);
	   }cout<<ans<<endl;
	}
	

	    
	return 0;
}
