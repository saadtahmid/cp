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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
class SGTree {
public: vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}
 
	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}
 
		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1] , seg[2 * ind + 2]);
	}
 
	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return INT32_MAX;
 
		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];
 
		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left,right);
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}
 
		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};
signed main()
{ ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n,q;cin>>n>>q;
    int arr[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    SGTree sg(n+1);sg.build(0,1,n,arr);
    for(int i=0;i<q;i++){string s;cin>>ws>>s;char c=s[0];
    s=s.substr(6);s.pop_back();stringstream ss;ss<<s;
          if(c=='q'){string token;
             getline(ss,token,',');
             int l=stoi(token);
             getline(ss,token,',');
             int r=stoi(token);
             cout<<sg.query(0,1,n,l,r)<<'\n';
          }else{
            vector<pii>v;string token;
            while(getline(ss,token,',')){
                int ind=stoi(token);
                v.pb({ind,arr[ind]});
            }
            v.push_back(v[0]);
            for(int j=0;j<v.size()-1;j++){
                int ind=v[j].first;
                int val=v[j+1].second;
                sg.update(0,1,n,ind,val);
                arr[ind]=val;
            }

          }
        
         
    }
  return 0;
}