#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n){
      //since special case josephus with k=2;
      //we can use binary trick
      int survivor=0;int ans=0;int done=0;
      while(!done){
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
               survivor=((n&~(1<<i))<<1)|1;
               if(survivor==n){ans+=2*n;done=1;break;}
               else{ans+=n-survivor;n=survivor;break;}
            }
        }
      }cout<<ans<<endl;
	}
	return 0;
}
