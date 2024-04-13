#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        char c;int m,n;
        cin>>c>>m>>n;int ans=0;
        //rook
        if(c=='r'){
            ans=min(m,n);
        }
        //queen
        if(c=='Q'){ans=min(m,n);}
        //king
        if(c=='K'){ans=((m+1)/2)*((n+1)/2);}
        //knight
        if(c=='k'){ans=((m+1)/2)*((n+1)/2)+(m/2)*(n/2);}
        cout<<ans<<'\n';
    }
    return 0;
}