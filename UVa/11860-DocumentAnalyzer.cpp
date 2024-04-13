#include <bits/stdc++.h>
using namespace std;
int main(){
   int k;cin>>k;
   for(int t=1;t<=k;t++){
    string s;set<string>st;vector<string>v;
    while(cin>>s){
        if(s=="END")break;
        string temp="";
        for(int i=0;i<s.size();i++){
           if(s[i]>='a'&&s[i]<='z')temp.push_back(s[i]);
           else{
            if(temp.size()>0){st.insert(temp);v.push_back(temp);};temp="";
           }
        }
        if(temp!=""){st.insert(temp);v.push_back(temp);}
    }
    set<string>st2;int len=INT_MAX;int p=1;int q=1;unordered_map<string,int>mp;set<int>st3;
     for(int i=v.size()-1;i>=0;i--){
        
        st2.insert(v[i]);if(mp[v[i]]){st3.erase(mp[v[i]]);}
        mp[v[i]]=i+1;st3.insert(i+1);
     if(st2.size()==st.size()){
        int first=*st3.begin();
        int last=*prev(st3.end());
       if(last-first+1<=len){
        len=last-first+1;
        p=first,q=last;
       }
     }
   }
   cout<<"Document "<<t<<": "<<p<<" "<<q<<'\n';
   }
    return 0;
}