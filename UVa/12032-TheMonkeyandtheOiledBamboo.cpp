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
bool possible(vector<int>&rungs,int k){
       int prev=0;
       for(int i=0;i<rungs.size();i++){
        if(rungs[i]-prev<k){prev=rungs[i];continue;}
        if(rungs[i]-prev>k)return 0;
        if(rungs[i]-prev==k){prev=rungs[i];k--;}
       }
       return 1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	for(int i=1;i<=t;i++){
       int n;cin>>n;
       vector<int>rungs(n);
       for(int j=0;j<n;j++)cin>>rungs[j];
       int low=rungs[0];
       int high=rungs[n-1];
       while(low<=high){
        int mid=(low+high)/2;
        if(possible(rungs,mid)){
            high=mid-1;
        }else{
            low=mid+1;
        }
       } 
       printf("Case %i: %d\n",i,low);  
    }
	return 0;
}
