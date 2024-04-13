#include <bits/stdc++.h>
using namespace std;
int month1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month2[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool consec(int d1,int m1,int y1,int d2,int m2,int y2){
    bool leap=false;
    if(y1%4==0&&y1%100!=0){leap =true;};
    if(y2-y1==1){
        if(d2==1&&m2==1&&d1==31&&m1==12){
            return true;
        }
    }
    if(y2-y1==0){  
      if(m2-m1==1){
        if(d2==1){
            if(leap){if(d1==month2[m1])return true;}
            else{if(d1==month1[m1])return true;}
        }
      }
      if(m2-m1==0){
        if(d2-d1==1)return true;
      }
    }
    return false;
}
int main(){
    while(1){int da;cin>>da;if (da==0)break;
     int d,m,y,c;
     cin>>d>>m>>y>>c;da--;long long ansd=0;long long anscost=0;
     while(da--){
       int nd,nm,ny,nc;
       cin>>nd>>nm>>ny>>nc;
       if(consec(d,m,y,nd,nm,ny)){
        ansd++;anscost+=(long long)(nc-c);
       }
       d=nd;m=nm;y=ny;c=nc;
     }
     cout<<ansd<<' '<<anscost<<'\n';
    }
    

    
    return 0;
}