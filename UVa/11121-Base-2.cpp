#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
#define vi vector<int>


signed main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    vi pow2(34);
    pow2[0] = 1;
    vi maxpow2(34);
    vi minpow2(34);
    maxpow2[0] = 1;
    minpow2[0] = 0;
    int maxs=1;
    int mins=0;
    for (int i = 1; i < 34; i++) {
        pow2[i] = abs(pow2[i - 1]) * 2;
        if(i%2!=0) pow2[i] *= -1;
        if(i%2!=0)mins+=pow2[i];
        else maxs+=pow2[i];
        maxpow2[i] = maxs;
        minpow2[i] = mins;
    }
    int t;
    cin >> t;
    for(int z=0;z<t;z++){ 
        int n;
        cin >> n;
        int i=0;
        cout<<"Case #"<<z+1<<": ";
        {
            for (i = 0; i < 34; i++) {
                if(n>=minpow2[i] && n<=maxpow2[i])break;
            }
         for(int j=i;j>=1;j--){
             if(n>=minpow2[j] && n<=maxpow2[j]   && !(n>=minpow2[j-1] && n<=maxpow2[j-1])){
                 cout<<1;
                 n-=pow2[j];
             }else cout<<0;
         }
         if(n==1)cout<<1;
         else cout<<0;
            
        }
        cout<<endl;
    }

}
