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
int solve(int n){
    if(n==0){return 0;}
    if(n==1){return 1;}
    return solve(n/2)+n%2;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,cas;
cin>>cas;
while(cas--)
{
cin>>n;
cout<<solve(n)<<endl;
}
	return 0;
}
