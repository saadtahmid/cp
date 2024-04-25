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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
    while(t--){
        int n,h;cin>>n>>h;
        string temp="";
        for(int i=0;i<n-h;i++)temp+='0';
        for(int i=0;i<h;i++)temp+='1';
        do{cout<<temp<<endl;}while(next_permutation(temp.begin(),temp.end()));
        if(t>1)cout<<endl;
    }
	
	
	return 0;
}
