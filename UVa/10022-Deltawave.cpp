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
 
    int t;
   cin>>t;
    loop(i,0,t)
    {   if(i!=0) cout<<endl;
        int s, t;
        cin >> s >> t;
        if (s > t)
            swap(s, t);
        s--;
        t--;
        int h1 = sqrt(s), h2 = sqrt(t);
        int mid1 = h1 * h1 + h1, mid2 = h2 * h2 + h2;
        int diff_x = mid1 - s - (mid2 - t);
        diff_x = abs(diff_x);
       
        int diff_y = h2 - h1;
        
        int orientation = 0; // up
        if ((s - h1) % 2)
            orientation = 1; // down

       

        if (diff_x >= diff_y)
        {
           cout<<diff_x+diff_y<<endl;
        }
        else if (orientation == 0)
        {
            int ans = 0;
            ans += 2 * diff_x;
            ans += diff_y - diff_x;
            ans += 2 * ((diff_y - diff_x) / 2);
            cout<<ans<<endl;
        }
        else
        {
            int ans = 0;
            ans += 2 * diff_x;
            ans += diff_y - diff_x;
            ans += 2 * (ceil((diff_y - diff_x) / 2.0));
           cout<<ans<<endl;
        }
        
    }
    return 0;
}
