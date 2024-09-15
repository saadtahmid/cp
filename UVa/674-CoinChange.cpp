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
int solve(int i,int n,int arr[],vector<vi> &dp)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    if(i==5)
    {
        return 0;
    }
    if(dp[i][n]!=-1)
    {
        return dp[i][n];
    }
    int ans=solve(i,n-arr[i],arr,dp)+solve(i+1,n,arr,dp);
    return dp[i][n]=ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[5]={1,5,10,25,50};
    int n=7489;
    vector<vi> dp(5,vi(n+1,0));
    loop(i,0,5)
    {
        dp[i][0]=1;
    }
    for(int i=4;i>=0;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(j-arr[i]>=0)
            {
                dp[i][j]+=dp[i][j-arr[i]];
            }
            if(i+1<5)
            {
                dp[i][j]+=dp[i+1][j];
            }
        }
    }
    while(cin>>n){
    
        cout<<dp[0][n]<<"\n";
    }
    
    return 0;
}