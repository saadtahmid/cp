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
double d_to_h(double d)
{
  double e = 6.11 * exp(5417.7530 * (1.0 / 273.16 - 1.0 / (d + 273.16)));
  return 0.5555 * (e - 10.0);
}
double h_to_d(double h)
{
  double f = (log((h / 0.5555 + 10.0) / 6.11)) / (5417.7530);
  double g = 1.0 / 273.16 - f;
  return (1.0 / g) - 273.16;
}
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(1);
  char a, b;
  double c, d;
  while (cin >> a)
  {
    if (a == 'E')
      break;
    cin >> c >> b >> d;
    if (a == 'T')
    { 
      if (b == 'D')
      {
        cout << "T " << c << ' ';
        cout << "D " << d << ' ';
        cout << "H " << c + d_to_h(d) << endl;
      }
      else
      {
        cout << "T " << c << ' ';
        cout << "D " << h_to_d(d - c) << ' ';
        cout << "H " << d << endl;
      }
    }
    else if (a == 'D')
    {
      if (b == 'T')
      {
        cout << "T " << d << ' ';
        cout << "D " << c << ' ';
        cout << "H " << d + d_to_h(c) << endl;
      }
      else
      {
        cout << "T " << d - d_to_h(c) << ' ';
        cout << "D " << c << ' ';
        cout << "H " << d << endl;
      }
    }
    else if (a == 'H')
    {
      if (b == 'D')
      {
        cout << "T " << c - d_to_h(d) << ' ';
        cout << "D " << d << ' ';
        cout << "H " << c << endl;
      }
      else
      {
        cout << "T " << d << ' ';
        cout << "D " << h_to_d(c - d) << ' ';
        cout << "H " << c << endl;
      }
    }
  }

  return 0;
}
