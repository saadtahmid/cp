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
void print(int i ,vi &pre,vi&v){
	if(pre[i]==-1){
      cout<<v[i]<<endl;return;
	}
	print(pre[i],pre,v);
    cout<<v[i]<<endl;
}
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
    int n;vi v;
	while(cin>>n){
		v.pb(n);
	}int len=0;int last=0;
    vi l(v.size()),l_ind(v.size()),pre(v.size());
	loop(i,0,v.size()){
      int pos=lower_bound(l.begin(),l.begin()+len,v[i])-l.begin();
	  l[pos]=v[i];
	  l_ind[pos]=i;
	  pre[i]=pos?l_ind[pos-1]:-1;
      if(pos==len){
		len++;
        last=i;
	  }else if(pos==len-1){
		last=i;
	  }
	}
	cout<<len<<endl<<'-'<<endl;;
    print(last,pre,v);
	return 0;
}