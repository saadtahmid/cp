#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    if(n<2)cout<<0<<endl;
    else {
        int cross=(n-2)*(n-2);
        double ans=n*n-cross;
        ans+=sqrt(2)*cross;
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    
}

signed main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline

    for(int i=1;i<=T;i++) {
        if(i>1)cout<<endl;
        solve();
         // Print blank line between test cases
    }
    return 0;
}
