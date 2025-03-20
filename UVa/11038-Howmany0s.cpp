#include <bits/stdc++.h>
using namespace std;
#define int long long
int countZero(int n) {
    if(n<0) return 0;
    int multiplier = 1;
    int sum=1;
    int remaining=0;
    while(n){
        if(n%10!=0){
            sum+=n/10*multiplier;
        }
        else{
            sum+=(n/10-1)*multiplier+remaining+1;
        }
        remaining+=n%10*multiplier;
        n/=10;multiplier*=10;
    }
    return sum;
}

signed main() {
    int n,m;
   while(  cin>>n>>m){
       if(n<0 && m<0) break;
       cout<<countZero(m)-countZero(n-1)<<endl;
   }
    return 0;
}
