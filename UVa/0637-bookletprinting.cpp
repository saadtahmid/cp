#include <bits/stdc++.h>
using namespace std;
int main(){
    
   while(1){

    int n;cin>>n;if(n==0)break;
    double times=ceil(n/4.0);int first=times*4,second=1,third=2,fourth=first-1;
    cout<<"Printing order for "<<n<<" pages:"<<'\n';
    for(int i=1;i<=times;i++){
        cout<<"Sheet "<<i<<", front: ";if(first>n){cout<<"Blank, ";}else{cout<<first<<", ";}cout<<second<<'\n';
        if(third<=n||fourth<=n){
        cout<<"Sheet "<<i<<", back : ";cout<<third<<", ";if(fourth>n){cout<<"Blank"<<'\n';}else{cout<<fourth<<'\n';};
        }
        first-=2;
        second+=2;
        third+=2;
        fourth-=2;
    }
    }
    
    return 0;
}