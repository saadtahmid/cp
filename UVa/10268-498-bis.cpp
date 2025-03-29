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
long long Pow(long long x, long long y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    while (cin >> x)
    {
        // take input a list of numbers in a single line separated by spaces and may be negative and store them in a vector
        vector<int> v;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        int num;
        while (ss >> num)
        {
            v.push_back(num);
        }
        reverse(v.begin(), v.end());
        int ans=0;
        loop(i,1,v.size()){
            ans+=v[i]*i*Pow(x,i-1);
        }
        cout<<ans<<endl;
    }
}
