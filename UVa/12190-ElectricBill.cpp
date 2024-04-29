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
int watt_bill(int watt){
    if(watt<=100)return 2*watt;
    if(watt<=10000)return 200+(watt-100)*3;
    if(watt<=1000000)return 200+(9900)*3+(watt-10000)*5;
    return 200+(9900)*3+(1000000-10000)*5+(watt-1000000)*7;
}
int bill_watt(int bill){
       int low=0;int high=1e9;
       while(low<=high){
        int mid=(low+high)>>1;
        if(watt_bill(mid)<bill){
            low=mid+1;
        }else if(watt_bill(mid)>bill){
            high=mid-1;
        }else{
            return mid;
        }
       }
       return -1;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int a,b;
	while(cin>>a>>b){
        if(a==0&&b==0)break;
        int totwatt=bill_watt(a);
        int low=0;int high=totwatt/2;int ans=-1;
        while(low<=high){
            int mid=(low+high)>>1;
            int mycost=watt_bill(mid);
            int ncost=watt_bill(totwatt-mid);
            
            if(ncost-mycost>b){
                low=mid+1;
            }
            else if(ncost-mycost<b){
                high=mid-1;
            }
            else{
                ans=mycost;break;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
