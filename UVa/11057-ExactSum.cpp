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
	int n;
	while(cin>>n){
		vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }int k;cin>>k;
    sort(v.begin(),v.end());
    int i=0,j=n-1;int ans1,ans2;
    while(i<j){
        if(v[i]+v[j]<k)i++;
        else if(v[i]+v[j]>k)j--;
        else{
          ans1=v[i];ans2=v[j];
          i++;j--;
        }
    }
    printf("Peter should buy books whose prices are %d and %d.\n",ans1,ans2);
        printf("\n");
    }
    

	return 0;
}
