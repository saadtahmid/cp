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
int jos(int n,int m){
    if(n==1)return 0;
    return (jos(n-1,m)+m)%n;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
    while(cin>>n,n){
        for(int m=1;m<=n;m++){
            //since 1 is killed always can start with cycle of n-1
            //where first member is 2
            int ans=jos(n-1,m)+1;
            //added 1 since starting from 2;
            //0 based indexing
            if(ans==(13-1)){cout<<m<<endl;break;}
        }
    }
	return 0;
}
