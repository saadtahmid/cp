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
class fenwick {vector<int>fen;
public:
fenwick(int n){
    fen.resize(n+1,0);
}
void update(int ind, int val)
{
	for(int i = ind;i<=fen.size(); i+= i & -i)
		fen[i] += val;
}

// Function to get the prefix sum or suffix sum 
int sum(int ind)
{
	int ans = 0; 
	for(int i = ind; i > 0 ; i-= i& -i)
		ans +=fen[i]; 

	return ans; 
}
int sum(int i,int j){
    return sum(j)-sum(i-1);
}
};
signed main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);string up,down;
	while(cin>>down>>up){int rmaxi=1e9;int lmaxi=1e9;
		for(int i=0;i<=down.size();i++){
            string temp(i,'0');
			temp=temp+up;int ok=1;
			for(int j=0;j<down.size()&&j<temp.size();j++){
				if(down[j]=='2'&&temp[j]=='2'){ok=0;break;}
			}
			if(ok){if(temp.size()>down.size()){rmaxi=temp.size();break;}else {rmaxi=down.size();break;}}
		}
        for(int i=1;i<=up.size();i++){
            string temp(i,'0');
			temp=temp+down;int ok=1;
			for(int j=0;j<up.size()&&j<temp.size();j++){
				if(up[j]=='2'&&temp[j]=='2'){ok=0;break;}
			}
			if(ok){if(temp.size()>up.size()){lmaxi=temp.size();break;}else {lmaxi=up.size();break;}}
		}
        cout<<min(rmaxi,lmaxi)<<'\n';
	}
    

    return 0;
}
