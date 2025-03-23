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
    o_set<int> st;
    for(int pow2=0;pow2<=31;pow2++)
    {
       for(int pow3=0;pow3<=20;pow3++)
       {
           for(int pow5=0;pow5<=14;pow5++)
           {
               for(int pow7=0;pow7<=12;pow7++)
               {
                   int num=pow(2,pow2);
                   num*=pow(3,pow3);
                   if(num>2e9) continue;
                     num*=pow(5,pow5);
                     if(num>2e9) continue;
                        num*=pow(7,pow7);
                     if(num>2e9) continue;
                   if(num>0)
                   {
                       st.insert(num);
                   }
               }
           }
       }
    }
    int k;
    while(cin>>k)
    {
        if(k==0) break;
        string pos;
        if(k%10==1 && k%100!=11) pos="st ";
        else if(k%10==2 && k%100!=12) pos="nd ";
        else if(k%10==3 && k%100!=13) pos="rd ";
        else pos="th ";
        cout<<"The "<<k<<pos<<"humble number is "<<*st.find_by_order(k-1)<<"."<<endl;
    }
    

    return 0;
}
