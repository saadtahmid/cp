#include <bits/stdc++.h>
using namespace std;
int main(){int N,i,j;
    while(cin>>N>>i>>j){
        int round =0;
        while(i!=j){
        i=ceil(i/2.0);
        j=ceil(j/2.0);
        round++;
        }
        cout<<round<<'\n';
    }
    
    return 0;
}