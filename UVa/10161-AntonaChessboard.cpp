#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        int x = ceil(sqrt(n));
        int y = x * x - x + 1;

        if (x % 2 != 0)
        {
            if (n <= y)
                cout << x << " " << x - (y - n) << endl;
            else
                cout << x - (n - y) << " " << x << endl;
        }
        else
        {
            if (n > y)
                cout << x << " " << x - (n - y) << endl;
            else
                cout << x - (y - n) << " " << x << endl;
        }
    }
    return 0;
}
