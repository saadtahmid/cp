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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
signed main()
{
  o_set<int> lucky;
  for(int i=1;i<2000000;i+=2){
   lucky.insert(i);
  }
  for(int i=2;i<lucky.size();i++){
   int pos=*lucky.find_by_order(i-1);pos--;
   for(int j=pos;j<lucky.size();j+=pos)
   {lucky.erase(*lucky.find_by_order(j));}
  }
 bool islucky[2000000+1]={0};
  for(auto it:lucky){
    islucky[it]=1;
  }
  int n;
  while(cin>>n){
    if(n==0||n&1){
        cout<<n<<" is not the sum of two luckies!\n";
    }else{int l1=0;int i=0;
	islucky[n/2]?i=lucky.order_of_key(n/2):i=lucky.order_of_key(n/2)-1;
       for( ;i>=0;i--){
             if(islucky[n-*lucky.find_by_order(i)]){l1=*lucky.find_by_order(i);break;}
        }
        cout<<n<<" is the sum of "<<l1<<" and "<<n-l1<<".\n";
    }
  }
  return 0;
}