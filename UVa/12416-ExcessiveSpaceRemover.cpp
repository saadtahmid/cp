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

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while(getline(cin, s))
    {
        int count=0;
        //calculate the lenth of maximum consecutive spaces
        int max=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                count++;
                if(count>max)
                {
                    max=count;
                }
            }
            else
            {   
                count=0;
            }
        }

        cout<<ceil(log2(max))<<endl;
    }
    

    return 0;
}
