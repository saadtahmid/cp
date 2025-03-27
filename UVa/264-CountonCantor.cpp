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
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)

signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   vi v;
   v.push_back(0);
   v.push_back(1);
   int j = 1;
   loop(i, 1, 10000000)
   {
      if (v.back() > 1e7)
         break;
      v.push_back(v.back() + j);

      j++;
   }

   int n;
   while (cin >> n)
   {
      int i = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;

      if (i % 2 == 0)
      {
         int diff = n - v[i];
         cout << "TERM " << n << " IS " << 1 + diff << "/" << i - diff << endl;
      }
      else
      {
         int diff = n - v[i];
         cout << "TERM " << n << " IS " << i - diff << "/" << 1 + diff << endl;
      }
   }
}
