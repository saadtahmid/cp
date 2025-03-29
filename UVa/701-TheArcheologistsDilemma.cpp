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
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) ;
        a = (a * a);
        b >>= 1;
    }
    return res;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int p;
  //let p=floor(2^N /10^t) where t is the difference in digits
  //p<=2^N /10^t < p+1
  //p*10^t <= 2^N < (p+1)*10^t
    //log2(p*10^t) <= N < log2((p+1)*10^t)
    //log2(p)+t*log2(10) <= N < log2(p+1)+t*log2(10)
  while(cin>>p){
    string s=to_string(p);
    ; double l;
    for(int t=s.size()+1;;t++){
        l=log2(p)+t*log2(10);
        double r=log2(p+1)+t*log2(10);
        if((int)l<(int)r){
            break;
        }
    }
    cout<<ceil(l)<<endl;
  }

   

   

  return 0;
}
