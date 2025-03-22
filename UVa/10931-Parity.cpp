#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
#define vi vector<int>



#define bitson __builtin_popcount 

signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0)break;
        int btz=bitson(n);
        //convert n to binary
        string s="";
        while(n>0){
            s+=to_string(n%2);
            n/=2;
        }
        reverse(s.begin(),s.end());
        cout<<"The parity of "<<s<<" is "<<btz<<" (mod 2)."<<endl;
    }

}
