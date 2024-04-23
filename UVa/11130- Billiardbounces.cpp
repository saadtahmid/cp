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
int solve(int n,int i){
	int round=0;
	while(n%i==1){
		round++;
		n=n-n/i-1;
	}
	if(round==i&&n%i==0)return 1;
	else return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,u,A,t;
	while(cin>>a>>b>>u>>A>>t){
       if(a==0&&b==0&&u==0&&A==0&&t==0)break;
	   double cosa=cos(A*3.14159/180);
	   double sina=sin(A*3.14159/180);
	   double x=(t*u*cosa);
	   x=round(x/(2*a));
	   double y=(t*u*sina);
	   y=round(y/(2*b));
	   cout<<x<<" "<<y<<endl;
	}
	return 0;
}
