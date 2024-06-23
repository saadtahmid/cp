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
void solve(int l, int r, int h) {
	if (l > r) return;
	int root;
	if (r - (1 << h) + 1 >= l) root = r - (1 << h) + 1; 
	else root = l;
	cout<<" "<<root;
	if (h == 0) return;
	solve(l, root - 1, h - 1);
	solve(root + 1, r, h - 1);
}

signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
    int n,h, cas = 0;
	while (cin>>n>>h,n||h) {
		cout<<"Case "<<++cas<<":";
		if ((1 << h) <= n) cout<<" Impossible.\n";
		else {
			solve(1, n, h - 1);
			cout<<endl;
		}
	}
	return 0;
}