#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int a,b;
        cin>>a>>b;
        if(a==0&&b==0)break;
        set<int>alice;
        set<int>betty;
        for(int i=0;i<a;i++){
            int x;
            cin>>x;
            alice.insert(x);
        }
        for(int i=0;i<b;i++){
            int x;
            cin>>x;
            betty.insert(x);
        }
        if(alice.size()<=betty.size()){
            int cnt=0;
            for(auto it:alice){
              if(betty.find(it)==betty.end()){
                 cnt++;
              }
            };cout<<cnt<<'\n';
        }else{int cnt=0;
            for(auto it:betty){
              if(alice.find(it)==alice.end()){
                 cnt++;
              }
            };cout<<cnt<<'\n';

        }

    }
    return 0;
}