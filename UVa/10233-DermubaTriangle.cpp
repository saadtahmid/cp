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
#define vi vector<int>
#define vvi vector<vi>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, t;
    while (cin >> s >> t)
    {
        if (s > t)
            swap(s, t);
        int h1 = sqrt(s), h2 = sqrt(t);
        int mid1 = h1 * h1 + h1, mid2 = h2 * h2 + h2;
        int diff_x = mid1 - s - (mid2 - t);
        diff_x = abs(diff_x);
        double distx = diff_x / 2.0;

        double disty = 0;
        int orientation = 0; // up
        if ((s - h1) % 2)
            orientation = 1; // down
        loop(i, h1, h2)
        {
            if (orientation == 0)
            {
                disty += 1 / sqrt(3);
            }
            else
            {
                disty += 2 / sqrt(3);
            }
            orientation ^= 1;
        }
        if (diff_x % 2 == 1)
        {
            if (orientation == 0)
            {
                disty -= 1 / (2 * sqrt(3));
            }
            else
            {
                disty += 1 / (2 * sqrt(3));
            }
        }

        double dist = sqrt(distx * distx + disty * disty);
        cout << fixed << setprecision(3) << dist << endl;
    }
}
