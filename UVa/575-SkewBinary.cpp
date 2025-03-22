#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string n;
    while(cin >> n)
    {
        if(n == "0") break;
        int m=2;
        int ans=0;
        for(int i=n.size()-1; i>=0; i--)
        {
            ans += (n[i]-'0')*(m-1);
            m *= 2;
        }
        cout << ans << endl;
    }
}
