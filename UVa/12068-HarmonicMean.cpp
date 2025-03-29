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
pii fraction_add(pii a, pii b) {
  int num = a.first * b.second + b.first * a.second;
  int den = a.second * b.second;
  int g = __gcd(num, den);
  return {num / g, den / g};
}
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  loop(i,1,t+1){
    int n;
    cin>>n;
    vi v(n);
    loop(i,0,n){
      cin>>v[i];
    }
    pii ans={0,1};
    loop(i,0,n){
      ans=fraction_add(ans, {1, v[i]});
    }
    int num=n*ans.second;
    int den=ans.first;
    int g=__gcd(num, den);
    num/=g;
    den/=g;
    cout<<"Case "<<i<<": "<<num<<"/"<<den<<endl;

  }
  return 0;
}
