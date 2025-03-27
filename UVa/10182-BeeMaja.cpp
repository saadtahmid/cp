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
   cin.tie(0);vi v;
   v.push_back(2);int j=6;
   loop(i, 1, 100000)
   {
      if (v.back() > 1e5)
         break;
      v.push_back(v.back() + j);
      j+=6;}
   int n;
   while(cin >> n)
   {
      if( n == 1)
      {
         cout<<0<<" "<<0<<endl;
         continue;
      }
      int i = upper_bound(v.begin(), v.end(), n) - v.begin() - 1;
      int start=v[i];
      int x=i,y=1;
      //6 loops for 6 directions
      while(start!=n&&x!=0)
      {
         start++;
         x--;
         y++;
      }
      
      while(start!=n&&x!=-y)
      {
         start++;
         x--;
      }
      
      while(start!=n&&y!=0)
      {
         start++;
         y--;
      }
      while(start!=n&&x!=0)
      {
         start++;
         x++;
         y--;
      }
      while(start!=n&&x!=-y)
      {
         start++;
         x++;
      }
      while(start!=n&&y!=0)
      {
         start++;
         y++;
      }
      cout<<x<<" "<<y<<endl;
   }
   }
