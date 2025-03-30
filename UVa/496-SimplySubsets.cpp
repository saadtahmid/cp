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
  string s, t;
  while(getline(cin, s) && getline(cin, t)) {
    set<int>A, B;
    stringstream ss(s), ss1(t);
    string x, y;
    while(ss >> x) {
      A.insert(stoi(x));
    }
    while(ss1 >> y) {
      B.insert(stoi(y));
    }
    int n = A.size(), m = B.size();
    set<int>C;
    if(n>=m)C = A;
    else C = B;
    int count = 0;
    for(auto it:C) {
      if(A.find(it) != A.end() && B.find(it) != B.end()) {
        count++;
      }
    }
    // 5 cases : A and B are equal, A is subset of B, B is subset of A, A and B are disjoint, A and B are intersecting
    if(count == n && count == m) {
      cout << "A equals B" << endl;
    } else if(count == n && count != m) {
      cout << "A is a proper subset of B" << endl;
    } else if(count != n && count == m) {
      cout << "B is a proper subset of A" << endl;
    } else if(count == 0) {
      cout << "A and B are disjoint" << endl;
    } else {
      cout << "I'm confused!" << endl;
    }
  }
    


  return 0;
}
