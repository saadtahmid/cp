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
	int n;
    //a(a+1)/2-b*b+1)/2=n
    //(a-b)(a+b+1)=2n
    //j*i=2n
    //bruteforce root(2n)
    
    while(cin>>n){int diff=0;int ans1,ans2;
        if(n==-1)break;
        for(int j=1;j*j<=2*n;j++){
            if(2*n%j)continue;
            int i=2*n/j;
            //i=a+b+1 j=a-b (i+j-1)/2=a
            int a=(i+j-1)/2;
            int b=a-j;
            if(a>=0&&b>=0&&(a-b)*(a+b+1)==2*n){
                if(a-b>diff){diff=a-b;ans1=a;ans2=b;}
            }
            
        }printf("%d = %d + ... + %d\n",n,ans2+1,ans1);

    }
	return 0;
}
