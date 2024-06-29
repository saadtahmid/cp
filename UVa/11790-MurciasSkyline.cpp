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
   int t;cin>>t;
   loop(l,1,t+1){
	int n;cin>>n;vi h(n),w(n);
    vi sumf(n),sumb(n);
	loop(i,0,n)cin>>h[i];
	loop(i,0,n)cin>>w[i];
	int maxi=0,maxd=0;
    loop(i,0,n){
		int sum1=w[i];
		int sum2=w[n-1-i];
		for(int j=i-1;j>=0;j--){
            if(h[i]>h[j]){
              sum1=max(sum1,sumf[j]+w[i]);
			}
		}
		for(int j=n-i;j<n;j++){
            if(h[n-1-i]>h[j]){
              sum2=max(sum2,sumb[j]+w[n-1-i]);
			}
		}
		sumf[i]=sum1;
		maxi=max(maxi,sumf[i]);
		sumb[n-1-i]=sum2;
        maxd=max(maxd,sumb[n-1-i]);
	}
	if(maxi>=maxd){
		printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",l,maxi,maxd);
	}else{
		printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",l,maxd,maxi);
	}
   }
	return 0;
}