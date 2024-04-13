#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int n;cin>>n;if(n==0)break;
        vector<int>v(n,-1);bool ok=true;
        for(int i=0;i<n;i++){
            int x,y;cin>>x>>y;int ps=i+y;if(ps<0 ||ps >=n||v[ps]!=-1)ok=false;
            if(ps>=0&&ps<n)v[ps]=x;
        }
        if(!ok)cout<<-1<<'\n';else{
            for(int i=0;i<n;i++){
                cout<<v[i];if(i!=n-1)cout<<' ';
            }cout<<'\n';
        }
    }
    return 0;
}