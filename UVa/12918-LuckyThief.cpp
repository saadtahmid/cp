#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N,M;
    cin >> N>>M;
    cout<<(M-N)*N+(N*(N-1))/2<<endl;
    
}

signed main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore newline

    while (T--) {
        solve();
         // Print blank line between test cases
    }
    return 0;
}
