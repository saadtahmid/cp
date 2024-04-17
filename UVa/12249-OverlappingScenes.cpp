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
#define endl "\n"
class fenwick {vector<int>fen;
public:
fenwick(int n){
    fen.resize(n+1,0);
}
void update(int ind, int val)
{
	for(int i = ind;i<=fen.size(); i+= i & -i)
		fen[i] += val;
}

// Function to get the prefix sum or suffix sum 
int sum(int ind)
{
	int ans = 0; 
	for(int i = ind; i > 0 ; i-= i& -i)
		ans +=fen[i]; 

	return ans; 
}
int sum(int i,int j){
    return sum(j)-sum(i-1);
}
};
signed main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;string s;
	for(int k=1;k<=t;k++){
		int n;cin>>n;vector<string>v;
		while(n--){
			cin>>s;
            v.pb(s);
		}int len=1e9;sort(v.begin(),v.end());
		do{
          string temp=v[0];
		  for(int i=1;i<v.size();i++){int start;int take=temp.size();
            for(start=0;start<temp.size();start++){
                 string suf=temp.substr(start);
				 string pref=v[i].substr(0,suf.size());
                 if(suf==pref){take=start;break;}
			}
			temp=temp.substr(0,take)+v[i];
		  }
		  len=min(len,(ll)temp.size());
		}while(next_permutation(v.begin(),v.end()));
		printf("Case %d: %d\n",k,len);
	}
	return 0;
}
