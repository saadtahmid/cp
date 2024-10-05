#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
// #define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)
#define MOD 1000000007
class dsu{
	
    public:
    vector<int>rank,parent,size;int numSets;
	dsu(int n){
		rank.resize(n+1,0);
		size.resize(n+1,1);
        parent.resize(n+1);
		for(int i=0;i<=n;i++){
			parent[i]=i;
		}
        numSets=n;
	}
	int findpar(int val){
		if(val==parent[val]){
			return val;
		}
		return parent[val]=findpar(parent[val]);
	}
	void unionByRank(int u,int v){
		int up_u=findpar(u);
		int up_v=findpar(v);
		if(up_u==up_v)return;
        if(rank[up_u]>rank[up_v]){swap(up_u,up_v);};
        parent[up_u] = up_v; 
        if (rank[up_u] == rank[up_v]) ++rank[up_v];  
        --numSets;
	}
	void unionBySize(int u,int v){
		int up_u=findpar(u);
		int up_v=findpar(v);
		if(up_u==up_v)return;
        if(size[up_u]>size[up_v]){swap(up_u,up_v);};
        parent[up_u] = up_v; 
        size[up_v] += size[up_u]; 
        --numSets;
	}
	bool isSameSet(int i, int j) { return findpar(i) == findpar(j); }
    int numDisjointSets() { return numSets; }
};
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    while(cin>>n>>m){
        if(n==0&&m==0)break;
    vector<pair<int,pii>>edges;
    dsu d(n);
    loop(i, 0, m) {
        int a, b,c;
        cin >> a >> b>>c;
        edges.pb({c,{a,b}});

    }
    sort(edges.begin(), edges.end(), greater<pair<int,pii>>());
    int maxi=edges[0].first;
    loop(i,0,m){
        if(edges[i].first!=maxi){
            break;
        }
        d.unionBySize(edges[i].second.first,edges[i].second.second);
    }
    int ans=0;
    loop(i,1,n+1){
        ans=max(d.size[i],ans);  
    }
    cout<<ans<<endl;}
    return 0;
}

