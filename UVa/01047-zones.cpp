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
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define endl "\n"
signed main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,r;int t=0;
	while(cin>>n>>r){t++;
		if(n==0&&r==0)break;if(t>1)printf("\n");vector<vector<int>>v;
		for(int i=0;i<n;i++){
			int x;cin>>x;
			v.pb({1,i+1,x});
		}
		int cm;cin>>cm;
		for(int i=0;i<cm;i++){
			int a;cin>>a;vector<int>temp;temp.pb(a);
			for(int j=0;j<a;j++){
				int y;cin>>y;temp.pb(y);
			}
			int val;cin>>val;temp.pb(val);
			v.pb(temp);
		}
		vector<int>comb;
		for(int i=0;i<n-r;i++){
			comb.pb(0);
		}
		for(int i=0;i<r;i++){
			comb.pb(1);
		}int total=0;vector<int>combo;
		do{
			vector<int>hash(n+1,0);vector<int>temp;
			for(int i=0;i<n;i++){
				if(comb[i]==1){hash[i+1]=1;temp.pb(i+1);}}
				int ans=0;
			for(int i=0;i<v.size();i++){
				if(v[i][0]==1&&hash[v[i][1]]){ans+=v[i][2];continue;}
                int cnt=0;
                for(int j=1;j<=v[i][0];j++){
                   if(hash[v[i][j]]){cnt++;}
				}
				if(cnt>1){
					ans-=(cnt-1)*v[i][v[i].size()-1];
					//cnt-1 because let subset is 1 3 4 now 
					//if in the commons there is 1 2 3 4 then we need to subtract the common part 
					// 2 times because this common part is included three times when we add  1 3 4 individually
					// but we need it one time so subtract the rest 2 times  
				}
			}	
			if(total<=ans){
				total=ans;combo=temp;
			}
		}while(next_permutation(comb.begin(),comb.end()));
		printf("Case Number %d\n",t);
           printf("Number of Customers: %d\n",total);
            printf("Locations recommended: ");
             for(int i=0;i<combo.size();i++)printf("%d ",combo[i]);
			 printf("\n");
		}
		

	    
	return 0;
}
