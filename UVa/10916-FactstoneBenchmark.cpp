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
    cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0) break;
        int y=(n-1960)/10+2;int i;
        double m=1<<y;
        for(i=1;;i++){
            m-=log2(i);
            if(m<=0) break;
        }
        cout<<i-1<<endl;
    }

}
