#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&a,pair<int,int>&b){
     if(a.first<b.first)return false;
     if(a.first>b.first)return true;
     else{
          return a.second>b.second;
     }

}
int main() {	
     int n;
     while(1){
          cin>>n;if(!n)break;
          vector<string>v(n);
          for(int i=0;i<n;i++){
               cin>>ws>>v[i];
          }
          sort(v.begin(),v.end());
          string ans="";
          for(int i=0;i<v[(n-1)/2].size();i++){
               if(v[(n-1)/2][i]!=v[n/2][i]){
                 ans+=v[(n-1)/2][i];break;
               }else{
                 ans+=v[(n-1)/2][i]; 
               }
          }
          if(ans.size()==v[(n-1)/2].size()){
               cout<<ans<<'\n';
          }else{
               ans[ans.size()-1]=ans[ans.size()-1]+1;
               if(ans==v[n/2]){int sz=ans.size();ans=v[(n-1)/2].substr(0,sz);for(int i=sz;i<v[(n-1)/2].size();i++){
                    if(v[(n-1)/2][i]=='Z'){
                     ans+='Z';
                    }else{
                         ans+=(v[(n-1)/2][i]+1);break;
                    }
               };if(ans.size()==v[(n-1)/2].size())ans=v[(n-1)/2];}
               cout<<ans<<'\n';
          }
     }
    
	return 0;
}