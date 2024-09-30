#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
#define MOD 1000000007
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //lol its just a fibonacci sequence just observe the pattern
    vi fib(86);
    fib[0]=0;
    fib[1]=1;
    loop(i,2,86)fib[i]=fib[i-1]+fib[i-2];
    int n;while(cin>>n){
        if(n==0)break;
        cout<<fib[n]<<endl;
    }

    return 0;}