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
  int num,den;
  while(cin>>num>>den){
    
    vi v;if(num<den)v.pb(0);
    while(1){
      if(num<den)swap(num,den);
      int q=num/den;
      v.pb(q);
      num=num-den*q;
      if(num==0)break;
      int g=__gcd(num,den);
      num/=g;
      den/=g;
    }
  cout<<"[";
  loop(i,0,v.size()){
    cout<<v[i];
    if(i==0&&i!=v.size()-1)cout<<";";
    else if(i!=v.size()-1)cout<<",";
  }
  cout<<"]"<<endl;
  
}
  return 0;
}
