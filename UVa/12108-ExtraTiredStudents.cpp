#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;int caseno=1;while(1){
        cin>>n;if(!n)break;vector<queue<int>>q(n),init(n);vector<int>bs(n);
        for(int i=0;i<n;i++){
         int a,b,c;cin>>a;for(int j=0;j<a;j++){
            q[i].push(1);init[i].push(1);
         }cin>>b;bs[i]=b;for(int j=0;j<b;j++){
            q[i].push(0);init[i].push(0);
         }cin>>c;
         for(int j=1;j<c;j++){
            q[i].pop();
         }
        }int error=1;
        for(int k=0;k<1000000;k++){int awake=0,sleep=0;
            for(int i=0;i<n;i++){
                 if(q[i].front()==0)sleep++;else awake++;
            }if(awake==n){cout<<"Case "<<caseno<<": "<<k+1<<'\n';error=0;break;}
            for(int i=0;i<n;i++){
                
                 int res=q[i].front();
                 if(q[i].size()==bs[i]+1){
                    if(sleep>awake)q[i].pop();else{
                       q[i]=init[i];
                    }
                 }else{q[i].pop();}if(q[i].empty()){
                   q[i]=init[i];
                  }
                }
            }if(error){cout<<"Case "<<caseno<<": "<<-1<<'\n';};caseno++;
        }

    
    return 0;
}