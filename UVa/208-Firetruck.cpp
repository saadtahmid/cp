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
void solve(int i,int n,vector<int>&used,vector<set<int>>&connections,vector<int>&canreach,vector<int>&temp,int &ans,vector<vector<int>>&anss){
	 if(i==n){temp.pb(i);ans++;anss.pb(temp);temp.pop_back();
     ;return;}
     used[i]=1;temp.pb(i);
     for(auto it:connections[i]){
         if(!used[it]&&canreach[it])solve(it,n,used,connections,canreach,temp,ans,anss);}
     used[i]=0;
     temp.pop_back();
}
void dfs(int i,vector<set<int>>&connections,vector<int>&canreach){
      canreach[i]=1;
      for(auto it:connections[i]){
        if(!canreach[it])dfs(it,connections,canreach);
      }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;int t=0;
	while(cin>>n){
		int a,b;t++;
        vector<int>used(21,0);vector<set<int>>connections(21);
        while(cin>>a>>b){
            if(a==0&&b==0)break;
            connections[a].insert(b);
            connections[b].insert(a);
        }vector<int>temp;int ans=0;vector<vector<int>>anss;vector<int>canreach(21,0);//canreach checks if target is reachable from that node
        dfs(n,connections,canreach);
        printf("CASE %d:\n",t);
        if(canreach[1])solve(1,n,used,connections,canreach,temp,ans,anss);
        for(int i=0;i<anss.size();i++){
            for(int j=0;j<anss[i].size();j++){
                if(j>0)printf(" ");
                printf("%d",anss[i][j]);
            }
            printf("\n");
        }
        printf("There are %d routes from the firestation to streetcorner %d.\n",ans,n);
	}
	return 0;
}
