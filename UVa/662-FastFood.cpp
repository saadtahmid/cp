#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
// #define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007
//Did this by myself (*_*)
int solve(int i, int prev, int k, vector<vector<vi>> &dp, vector<vi> &costs)
{
    if (i == costs.size() - 1)
    {
        if (k == 0)
        {
            return dp[i][prev][k] = costs[prev][i];
        }
        return 1e9;
    }
    if (dp[i][prev][k] != -1)
        return dp[i][prev][k];
    int take = 1e9;
    if (k > 0)
        take = solve(i + 1, i, k - 1, dp, costs) + costs[prev][i]; // place the depot
    int nottake = solve(i + 1, prev, k, dp, costs);                // don't place the depot
    return dp[i][prev][k] = take < nottake ? take : nottake;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    int t = 1;
    while (cin >> n >> k)
    {
        if (n == 0 && k == 0)
            break;
        vi a(n + 1, 0);
        loop(i, 1, n + 1) cin >> a[i];
        vector<vi> costs(n + 2, vi(n + 2, 0)); // costs[i][j] calculates the dist of all restaurants in between if depot is at i and j
        loop(i, 0, n + 2)
        {
            loop(j, 0, n + 2)
            {
                if (i == j || (i == 0 && j == n + 1))
                    continue;
                loop(k, i + 1, j)
                {
                    if (i == 0)
                        costs[i][j] += abs(a[j] - a[k]);
                    else if (j == n + 1)
                        costs[i][j] += abs(a[i] - a[k]);
                    else
                        costs[i][j] += min(abs(a[i] - a[k]), abs(a[j] - a[k]));
                }
            }
        }
        vector<vector<vi>> dp(n + 2, vector<vi>(n + 2, vi(k + 1, -1))); // dp[i][j][k] calculates the min dist
        // if current depot is at i and prev is at j and k depots are left
        int ans = solve(1, 0, k, dp, costs);
        vi path;
        int prev = 0;
        int k2 = k;
        // backtrack to find the path
        loop(i, 1, n + 1)
        {
            if (k2 == 0)
                break;
            if (dp[i][prev][k2] == dp[i + 1][prev][k2])
            {
            }
            else
            {
                path.pb(i);
                k2--;
                prev = i;
            }
        }
        cout << "Chain " << t++ << endl;
        int leftbound = 1;
        // print the path by keeping track of left and right bound
        loop(i, 0, path.size())
        {
            int ai = a[path[i]];
            int rightbound;
            if (i == path.size() - 1)
                rightbound = n;
            else
            {
                rightbound = path[i];
                int aj = a[path[i + 1]];
                loop(k, path[i] + 1, path[i + 1])
                {
                    if (a[k] - ai > aj - a[k])
                    {
                        break;
                    }
                    rightbound = k;
                }
            }
            cout << "Depot " << i + 1 << " at restaurant " << path[i] << " serves restaurants " << leftbound << " to " << rightbound << endl;
            leftbound = rightbound + 1;
        }
        cout << "Total distance sum = " << ans << endl
             << endl;
    }

    return 0;
}