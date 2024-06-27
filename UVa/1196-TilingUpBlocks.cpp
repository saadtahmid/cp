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
    int n;;
	while(cin>>n){
		if(n==0){cout<<'*'<<endl;break;};
		vector<pii>v(n);
		loop(i,0,n){
			int a,b;cin>>a>>b;
            v[i]={a,b};
		}
		srt(v);
		int len=0;
    vi l(v.size());
	loop(i,0,v.size()){
      int pos=upper_bound(l.begin(),l.begin()+len,v[i].second)-l.begin();
	  l[pos]=v[i].second;
      if(pos==len){
		len++;
	  }
	}
	cout<<len<<endl;
	}
	return 0;
}