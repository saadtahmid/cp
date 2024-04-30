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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
double timediff(double r,vector<pair<double,double>>&v,int d){
    auto me=v[v.size()-1];
    double mytime=r/me.first+(d-r)/me.second;
    double other=1e9;;
    for(int i=0;i<v.size()-1;i++){
          auto o=v[i];
          other=min(other,r/o.first+(d-r)/o.second);
    }
    return other-mytime;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int d;
	while(cin>>d){
        int n;cin>>n;
        vector<pair<double,double>>v(n);
       double low=0,high=d;
       for(int i=0;i<n;i++){
         double r,c;cin>>r>>c;
         v[i].first=r;v[i].second=c;
       }
       while(high-low>=1e-5){
        double m1=low+(high-low)/3;
        double m2=high-(high-low)/3;
        double tm1=timediff(m1,v,d);
        double tm2=timediff(m2,v,d);
        if(tm1>tm2){
            high=m2;
        }else if(tm1<tm2){
            low=m1;
        }else{
            low=m1;
            high=m2;
        }
       }
       double ans=(high+low)/2;
       double wintime=timediff(ans,v,d)*3600;
       if(wintime-0>=-(1e-2)){
        printf("The cheater can win by %.0lf seconds with r = %.2lfkm and k = %.2lfkm.\n",abs(wintime),ans,d-ans);
       }
       else{
        printf("The cheater cannot win.\n");
       }
    }
	return 0;
}
