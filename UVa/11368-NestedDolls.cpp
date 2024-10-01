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
bool comp(pii a,pii b){
  if(a.first==b.first)return a.second<b.second;//doing this ensures if there is tie they are  taken in diff box
  return a.first>b.first;
}
signed main(){
   ios::sync_with_stdio(false);
 cin.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n;cin>>n;
    vector<pii>v;
    loop(i,0,n){
      int x,y;cin>>x>>y;
      v.pb({x,y});
    }
    sort(v.begin(),v.end(),comp);
    vi l(n);int len=0;
    //here lis doesnt represent how many i am taking 
    //observe that the v.first are sorted in descending 
    //but for second i am finding lis
    //it means the lis shows how many dolls I cant have in the same box  
    //after 50 if i get 60 i am inserting him in lis but it means 50 and 60 are in different box
    //after 50 if i get 40 i am inserting him in lis but it does not increase size of lis so they in same box
    //use upper bound to get same value in lis since if width of two are same they will be indiff box
    //could use multiset too
    loop(i,0,v.size()){
      int pos=upper_bound(l.begin(),l.begin()+len,v[i].second)-l.begin();
      l[pos]=v[i].second;
      if(pos==len){
        len++;
      }
    }
    cout<<len<<endl;
  }
    
    return 0;
}