#include <bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(),x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
   int n;
   while(cin>>n,n){
    priority_queue<int,vector<int>,greater<int>>pq;
    loop(i,0,n){
        int x;cin>>x;
        pq.push(x);
    }int ans=0;
    while(pq.size()>1){
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        ans+=a+b;
        pq.push(a+b);
    }
    cout<<ans<<endl;
   }
    return 0;
}