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
#define vi vector<int>
#define pb push_back
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int m;cin>>m;vi arr(m);
        loop(i,0,m)
        {
            cin>>arr[i];
        }
        vector<vi> dp(m+1,vi(n+1,INT64_MAX));    
        for(int i=m-1;i>=0;i--)
        {
            loop(j,0,n+1){
                int take;
                int leave=dp[i+1][j];
                if(j-arr[i]<=0)
                {
                    take=arr[i]-j;
                }else take=dp[i+1][j-arr[i]];
                dp[i][j]=min(take,leave);
            }
        }
        int target=dp[0][n]+n;
        cout<<target<<" ";
        vector<vi> dp2(m+1,vi(target+1,INT32_MAX));    
        loop(i,0,m+1)
        {
            dp2[i][0]=0;
        }
        for(int i=m-1;i>=0;i--){
            loop(j,0,target+1){
                dp2[i][j]=min(dp2[i+1][j],j-arr[i]>=0?1+dp2[i+1][j-arr[i]]:INT64_MAX);
            }
        }
        cout<<dp2[0][target]<<endl;
    }
    
    return 0;
}