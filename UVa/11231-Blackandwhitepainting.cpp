#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, m, c;
    while (cin >> n >> m >> c)
    {
        if (n == 0 && m == 0 && c == 0)
            break;

        if (c == 0)
        {
            int rmax = (n - 7) / 2;
            int cmax = (m - 7) / 2;
            int rsum = rmax * (rmax + 1);
            if (n % 2 != 0 && rmax > 0)
                rsum -= rmax;
            int csum = cmax * (cmax + 1);
            int delsum = 0;
            if (m % 2 != 0 && cmax > 0)
                csum -= cmax;

            if (rsum > csum)
            {
                int rn = (n - m) / 2;
                delsum = rn * (rn + 1);
                if ((n-m) % 2 == 0)
                    delsum -= rn;
            }
            else if (csum > rsum)
            {
                int cn = (m - n) / 2;
                delsum = cn * (cn + 1);
                if ((m-n) % 2 == 0)
                    delsum -= cn;
            }
            cout << rsum + csum - delsum << endl;
        }
        if (c == 1)
        {   
            if(m>n) swap(n,m);
            int rmax = (n - 6) / 2;
            int cmax = (m - 8) / 2;
            int rsum = rmax * (rmax + 1);
            if (n % 2 == 0 && rmax > 0)
                rsum -= rmax;
            int csum = cmax * (cmax + 1);
            int delsum = 0;
            if (m % 2 == 0 && cmax > 0)
                csum -= cmax;

            if (rsum > csum)
            {
                int rn = (n - m+1) / 2;
                delsum = rn * (rn + 1);
                if ((n-m) % 2 != 0)
                    delsum -= rn;
            }
            else if (csum > rsum)
            {
                int cn = (m - n+1) / 2;
                delsum = cn * (cn + 1);
                if ((m-n) % 2 != 0)
                    delsum -= cn;
            }
            cout << rsum + csum - delsum << endl;
        }
    }
    return 0;
}
