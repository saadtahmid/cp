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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        int mat[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        int q;
        cin>>q;
        while(q--){
             int l,r;
             cin>>l>>r;
            int curr_max=0;
             for(int i=0;i<n;i++){//for each row check greatest square by checking diagonal
             //then for next row start from size of square with previous ans becasue need greatest size
             //of square if for row 1 got size 3 no use  of starting from < 3
                int min_ind=lower_bound(mat[i],mat[i]+m,l)-mat[i];
                for(int j=curr_max;j<n;j++){
                    if(min_ind+j>=m||i+j>=n||mat[i+j][min_ind+j]>r)break;
                    if(j+1>curr_max)curr_max=j+1;
                }
             }
             cout<<curr_max<<endl;
        }
        cout<<'-'<<'\n';
    }
    

	return 0;
}
