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
  cout << fixed << setprecision(2);
  //we will deal in cents rather than dollars to avoid floating point errors
  //we will find average cents and the remainder cents
  //we will not always make it equal to average because we have some remaining cents
  //so we will not make = average rather average + 1 since if they pay equal to average then we will have some cents remaining
  //so we will make it average + 1 for some people and average for some people
  // so as long as we have remaining cents we make equal t  o average + 1 so make less transfers and also decrease the remaining cents
  int n;
  while (1)
  {
    cin >> n;
    if (n == 0)
      break;
    vector<int> a(n);
    int sum = 0;
    loop(i, 0, n)
    {
      string x;
      cin >> x;
      int j = x.find('.');
      string y = x.substr(0, j);
      string z = x.substr(j + 1);
      y = y + z;
      a[i] = stoi(y);

      sum += a[i];
    }

    int avg = sum / n;
    int rem = sum % n;
    int transfered = 0;
    loop(i, 0, n)
    {
      if (a[i] > avg)
      {
        transfered += a[i] - avg;
        if (rem > 0)
        {
          transfered--;
          rem--;
        }
      }
    }
    cout << "$" << (transfered) / 100.0 << endl;
  }

  return 0;
}
