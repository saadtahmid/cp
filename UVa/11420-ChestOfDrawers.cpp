#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(),x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(66, vector<int>(66, 0)));
    
    // Base cases for l = 0
    dp[0][0][0] = 1;
    dp[1][0][0] = 1;
    
    for (int i = 1; i <= 65; i++) {
        for (int j = 0; j <= i; j++) {
            // Previous unlocked drawer
            dp[0][i][j] = dp[0][i - 1][j] + dp[1][i - 1][j];
            
            // Previous locked drawer
            dp[1][i][j] = dp[0][i - 1][j];
            if (j > 0) dp[1][i][j] += dp[1][i - 1][j - 1];
        }
    }
    int l,s;
    while (true) {
        cin >> l >> s;
        if(l<0&&s<0)break;
        
        cout << dp[1][l][s]<<endl;
    }
    return 0;}