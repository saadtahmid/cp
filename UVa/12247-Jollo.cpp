#include <bits/stdc++.h>
using namespace std;
int main(){
    while(1){
        int a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;if(a==0 &&b==0&&c==0&&x==0&&y==0)break;
        int hash[53]={0};
        hash[a]=1;
        hash[b]=1;
        hash[c]=1;
        hash[x]=1;
        hash[y]=1;
        
        int lg=min(min(a,b),c);
        int hg=max(max(a,b),c);
        int midg=a+b+c-lg-hg;
        int hp=max(x,y);
        int lp=min(x,y);
        int cnt=0;
        if(midg>lp &&hg>hp){cout<<-1<<'\n';}
        else if(hg<lp){for(int i=1;i<53;i++){
           if(hash[i]!=1){cout<<i<<'\n';break;}}}
        else if(lp>midg){int ok=0;for(int i=midg;i<53;i++){
           
           if(hash[i]!=1){cout<<i<<'\n';ok=1;break;}
        };if(ok==0)cout<<-1<<'\n';}else if(hp>hg){int ok=0;for(int i=hg;i<53;i++){
           if(hash[i]!=1){cout<<i<<'\n';ok=1;break;}
        };if(ok==0)cout<<-1<<'\n';}
    }
    return 0;
}