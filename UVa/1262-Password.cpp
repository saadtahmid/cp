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
void solve(vector<set<char>>&grid,int cnt,int target){
    map<string,int>hash;
   for(auto i:grid[0]){
            for(auto j:grid[1]){
                for(auto k:grid[2]){
                    for(auto l:grid[3]){
                        for(auto m:grid[4]){
                                string s="";
                                s+=i;
                                s+=j;
                                s+=k;
                                s+=l;
                                s+=m;
                            if(hash[s])continue;
                            cnt++;
                            if(cnt==target){
                                cout<<s<<endl;return;
                            }
                            if(cnt>target){cout<<"NO"<<endl;return;}
                        }
                    }
                }
            }
        }
        cout<<"NO"<<endl;return;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;cin>>t;
	while(t--){
		int k;cin>>k;vector<vector<int>>v(5,vector<int>(26,0));
        for(int i=0;i<6;i++){
            for(int j=0;j<5;j++){
                char x;cin>>x;v[j][x-'A']++;
            }
        }vector<set<char>>grid(5);
         for(int i=0;i<6;i++){
            for(int j=0;j<5;j++){
                char x;cin>>x;
                if(v[j][x-'A']){
                    grid[j].insert(x);
                }
            }
        }
        solve(grid,0,k);
        ;
	}
	return 0;
}

 