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
#define vi vector<int>
#define vvi vector<vi>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
int t;
cin >> t;
while (t--){
  int n;cin>>n;
  int ans=0;
  int i;int lastq=0;
  for(i=1;i*i<=n;i++){
    int q=n/i;
    ans+=q;
    ans+=(i-1)*(lastq-q);
    lastq=q;
  }
 if((i-1)!=lastq) ans+=(i-1)*(lastq-n/i);
  cout<<ans<<endl;
}


  return 0;
}
