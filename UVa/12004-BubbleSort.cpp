#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int den=n*(n-1)/2;
    if(den%2==0)
        cout<<den/2<<endl;
    else
        cout<<den<<'/'<<2<<endl;
    
}

signed main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline

    for(int i=1;i<=T;i++) {
        cout<<"Case "<<i<<": ";
        solve();
         // Print blank line between test cases
    }
    return 0;
}
