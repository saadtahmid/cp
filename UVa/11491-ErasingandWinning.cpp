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
    int d,n;
	while (cin>>d>>n,n||d) {
		string s;cin>>s;int x=n;
		string temp;temp.pb(s[0]);
		loop(i,1,d){
			while(!temp.empty()&&temp.back()<s[i]&&n){
				temp.pop_back();n--;
			}
			temp.pb(s[i]);
		}
	   
		loop(i,0,d-x)cout<<temp[i];
		cout<<endl;
	}
	return 0;
}