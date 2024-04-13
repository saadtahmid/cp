#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;cin>>ws>>s;
        double co1=0,co2=0,const1=0,const2=0;bool equalsign=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='='){equalsign=true;continue;}
            bool neg=false;double num=0;bool immdtx=false;
            if(s[i]=='-'){neg=true;i++;}else if(s[i]=='+'){i++;}
            if(s[i]=='x'){immdtx=true;}
            while(s[i]>='0'&&s[i]<='9'){
                num=num*10+(s[i]-'0');i++;
            }
            if(s[i]=='x'){if(immdtx)num=1;if(neg)num=num*(-1);if(equalsign){co2+=num;}else{co1+=num;}}else{if(neg)num=num*(-1);
                if(equalsign){const2+=num;}else{const1+=num;}
                i--;
            }
        }
        double xco=co1-co2;double consta=const2-const1;
        if(xco==0){
            if(consta==0){cout<<"IDENTITY"<<'\n';}else{
                cout<<"IMPOSSIBLE"<<'\n';
            }
        }else{
            cout<<(int)floor(consta/xco)<<'\n';
        }
    }
    return 0;
}