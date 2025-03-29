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

//ruffini's rule
vector<double> poly_division(double root,vector<double> &equation){
    int n = equation.size();
    vector<double> result(n);
    result[0] = equation[0];
    for(int i=1;i<n;i++){
        result[i] = equation[i]+root*result[i-1];
    }
    return result;
}
signed main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t;
    cin >> t;
    while(t--){
      int n;cin>>n;
      vector<double> v(n+1);
      loop(i,0,n+1)cin>>v[i];
      vector<double> roots(n-2);
      loop(i,0,n-2)cin>>roots[i];
      loop(i,0,n-2){
        v = poly_division(roots[i],v);
      }
      //use b^2-4ac to find the roots of the quadratic equation
      double a = v[0], b = v[1], c = v[2];
      double d = b*b-4*a*c;
      if(d<0){
        cout<<"No real roots"<<endl;
      }else if(d==0){
        double root = -b/(2*a);
        cout<<fixed<<setprecision(1)<<root<<endl;
        cout<<fixed<<setprecision(1)<<root<<endl;

      }else{  
        double root1 = (-b+sqrt(d))/(2*a);
        double root2 = (-b-sqrt(d))/(2*a);
        cout<<fixed<<setprecision(1)<<root1<<endl;
        cout<<fixed<<setprecision(1)<<root2<<endl;
      }
    }

   

   

  return 0;
}
