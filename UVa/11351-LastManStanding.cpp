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
int jos(int n,int k){
    if(n==1)return 0;
    return (jos(n-1,k)+k)%n;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
    for(int i=1;i<=t;i++){
          int n,k;cin>>n>>k;
          //classic josephus problem
          int ans=jos(n,k)+1;//since recursion in 0 based 
          printf("Case %d: %d\n",i,ans);
    }
	return 0;
}
