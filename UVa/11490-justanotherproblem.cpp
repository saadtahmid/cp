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
	int n;int mod=100000007;
    //let t=thickness s =square side
    //since 2 squares it divides the row/column
    //into 3 equal t similarly divides the 
    //corresponding column/row into 2 equal t;
    //so n+2*s^2=(3*t+2*s)(2*t+s)
    //simplifying : n=t(6t+7s)
    while(cin>>n,n){
        int found=0;
        for(int t=1;t*t<=n;t++){
            if(n%t)continue;
            int sixtplus7s=n/t;
            int s=(sixtplus7s-6*t);
            //should check right now because s changes after %mod
            if(s%7>0||s<=0)continue;
            s=(s/7)%mod;
            if(s>0){printf("Possible Missing Soldiers = %d\n",(2*s*s)%mod);found=1;}
        }if(!found)printf("No Solution Possible\n");
        printf("\n");
    }
	return 0;
}
