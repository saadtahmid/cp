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
bool binfind(vector<int>&arr,int target){
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target)return 1;
            if(arr[mid]>target){
                high=mid-1;
            }
            else{low=mid+1;}
        }
        return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    //the answer has to be someone in the sets of producer or 0
    //because if the answer is not in the set can get the next smallest
    //in producers set and still get same or//better ans 
    int t;cin>>t;
    while(t--){
        int p,c;
        cin>>p>>c;
        vector<int>ps;
        vector<int>cs;
        for(int i=0;i<p;i++){
            int x;cin>>x;
            ps.pb(x);
        }
        for(int i=0;i<c;i++){
            int x;cin>>x;
            cs.pb(x);
        }set<int>st;
        st.insert(0);
        for(int i=0;i<p;i++){
             st.insert(ps[i]);
        }
        sort(ps.begin(),ps.end());
        sort(cs.begin(),cs.end());
      
        int ans1;int ans2=1e9;
        
        for(auto it:st){
             int punhappy=ps.size()-(upper_bound(ps.begin(),ps.end(),it)-ps.begin());
             int cunhappy=lower_bound(cs.begin(),cs.end(),it)-cs.begin();
             if(punhappy+cunhappy<ans2){
                ans2=punhappy+cunhappy;
                ans1=it;
             }
             }  cout<<ans1<<" "<<ans2<<endl;  
        }
	return 0;
}
