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
pair<int,int> getdiff(int root,int start,int end,vector<int>&prefixsum){
    int left=0;int right=0;
    // left sum.
    if(start+1<=root){left+=prefixsum[root-1];   if(start>0){
        left-=prefixsum[start-1];
    }}
 
    // right sum.
    if(end-1>=root)right+=prefixsum[end]-prefixsum[root];
    return {left,right};
}
string makebst(int start,int end,vector<int>&v,vector<int>&prefixsum){
        if(start==end){// only one node - make root and return;
            return to_string(v[start]);
        }
        int root,sumleft=-1e9,reqdiff=1e9;
        for(int i=start;i<=end;i++){
            //if duplicate rightmost should be root
            if(i+1<=end&&v[i]==v[i+1])continue;
            pii lr=getdiff(i,start,end,prefixsum);
            int diff=abs(lr.first-lr.second);
            // this sum is smaller than current or sum is equal but left tree sum is greater.
            if(diff<reqdiff||(reqdiff==diff&&sumleft<lr.first)){
                root=i;// make i the root.
                sumleft=lr.first;
                reqdiff=diff;

            }     
        }string ans=to_string(v[root]);
            if(root!=start&&root!=end){
               ans+="("+makebst(start,root-1,v,prefixsum)+","+makebst(root+1,end,v,prefixsum)+")";
            }else if(
                root!=start
            ){
                ans+="("+makebst(start,root-1,v,prefixsum)+")";
            }else if( root!=end) {
                ans+="("+makebst(root+1,end,v,prefixsum)+")";
            }
         return ans;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;cin>>q;
    for(int t=1;t<=q;t++){
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
         // sort so that if we make ith as root then all smaller will lie on left.
        sort(v.begin(),v.end());
         // prefix sum, to get left sum and right sum in O(1)
        vector<int>prefixsum(n);prefixsum[0]=v[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=v[i]+prefixsum[i-1];
        }
        string ans=makebst(0,n-1,v,prefixsum);
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

	return 0;
}
