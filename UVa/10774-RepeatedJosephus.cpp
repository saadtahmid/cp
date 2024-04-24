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
	cin.tie(NULL);int t;cin>>t;
	
	for(int j=1;j<=t;j++){
      //since special case josephus with k=2;
      //we can use binary trick
     int round=0;int survivor;int n;cin>>n;
     //basically 2^n -1
     while((n&(n+1))!=0){
        for(int i=31;i>=0;i--){
            if(n&(1<<i)){
               survivor=((n&~(1<<i))<<1)|1;n=survivor;
               round++;break;
            }
        }
     }printf("Case %d: %d %d\n",j,round,n);
	}
	return 0;
}
