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
   int n,k;
   while(cin>>n>>k){
       if(n==-1 && k==-1) break;
       vi v(n+1);
       loop(i,0,n+1){
           cin>>v[i];
       }
       for(int i=n;i>=0;i--){
           if(i<k)break;
            int j=i-k;
            int c=v[i];
            v[j]-=c;
            v[i]=0;
       }
       
       int l=k-1;
       if(l>n) l=n;  
       while(v[l]==0)l--;
       if(l<0) l=0;
       for(int i=0;i<=l;i++){
             if(i!=0) cout<<" ";
         cout<<v[i];
       }
       
         cout<<endl;


   }

   

  return 0;
}
