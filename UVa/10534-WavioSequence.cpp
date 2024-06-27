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
		vi v(n);
		loop(i,0,n){
			cin>>v[i];
		}
		int len1=0,len2=0;
    vi frontlis(v.size()),backlis(v.size());
	vi hash1(n),hash2(n);
	loop(i,0,v.size()){
      int posf=lower_bound(frontlis.begin(),frontlis.begin()+len1,v[i])-frontlis.begin();
      int posb=lower_bound(backlis.begin(),backlis.begin()+len2,v[n-1-i])-backlis.begin();
	  frontlis[posf]=v[i];
	  backlis[posb]=v[n-1-i];
	  hash1[i]=posf+1;
	  hash2[n-1-i]=posb+1;
      if(posf==len1){
		len1++;
	  }
	  if(posb==len2){
		len2++;
	  }
	}int ans=0;
	loop(i,0,n){
      ans=max(ans,2*min(hash1[i],hash2[i])-1);
	}
	cout<<ans<<endl;
	}
	return 0;
}