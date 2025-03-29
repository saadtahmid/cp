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
pii fraction_add(pii a, pii b)
{
  int num = a.first * b.second + b.first * a.second;
  int den = a.second * b.second;
  int g = __gcd(num, den);
  return {num / g, den / g};
}
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  while (cin >> s)
  {
    if (s == "0")
      break;
    string temp = "";
    for (int i = 2; i < s.size() - 3; i++)
    {
      temp += s[i];
    }
    int n = stoi(temp);
    int ans_num = 1, ans_den = 1e9;
    for (int i = 0; i < temp.size(); i++)
    {
      int num = n - (n / (int)pow(10, i + 1));
      int den = pow(10, temp.size()) - pow(10, temp.size() - i - 1);

      int g = __gcd(num, den);
      num /= g;
      den /= g;

      if (den < ans_den)
      {
        ans_num = num;
        ans_den = den;
      }
    }
    cout << ans_num << "/" << ans_den << endl;
  }

  return 0;
}
