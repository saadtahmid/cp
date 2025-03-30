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
  string s;
  int j;int i=1;
  while(1){
    cin>>j;
 if(j==-1)break;
    cin>>s;
    string temp=s.substr(2);
    int n=stoi(temp);
    if(j==0){
      int num=n;
      int den=pow(10,temp.size());
      int g=__gcd(num,den);
      num/=g;
      den/=g;
      cout<<"Case "<<i<<": "<<num<<"/"<<den<<endl;
      i++;
      continue;
    }
    int num=n-(n/(int)pow(10,j));
    int den=pow(10,temp.size())-pow(10,temp.size()-j);
    int g=__gcd(num,den);
    num/=g;
    den/=g;
    cout<<"Case "<<i<<": "<<num<<"/"<<den<<endl;
    i++;
  }
  return 0;
}
