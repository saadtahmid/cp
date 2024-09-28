#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
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
#define MOD 1000000007
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<fixed;   
    cout.precision(2);
    int n;int network_number = 1;
    while(cin>>n,n){
        vector<vector<double>>dist(n,vector<double>(n,0));
        int  x,y;
        vector<pii>points(n);
        loop(i,0,n){
            cin>>x>>y;
            points[i]={x,y};
        }
        loop(i,0,n){
            loop(j,0,n){
                    if(i==j)continue;
                    dist[i][j]=sqrt(pow(points[i].first-points[j].first,2)+pow(points[i].second-points[j].second,2))+16;
            }
        }vi final;
        vi perms;
        loop(i,1,n+1){
            perms.pb(i);
        }
        double ans=1e9;
        do{
            double temp=0;
            loop(i,0,n-1){
                temp+=dist[perms[i]-1][perms[i+1]-1];
            }
            if(temp<ans){
                ans=temp;
                final=perms;
            }}while(next_permutation(perms.begin(),perms.end()));
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<network_number++<<endl;
        loop(i,0,n-1){
            cout<<"Cable requirement to connect ("<<points[final[i]-1].first<<","<<points[final[i]-1].second<<") to ("<<points[final[i+1]-1].first<<","<<points[final[i+1]-1].second<<") is "<<dist[final[i]-1][final[i+1]-1]<<" feet."<<endl;
        }  
        cout<<"Number of feet of cable required is "<<ans<<"."<<endl;
    }
    
    return 0;}
