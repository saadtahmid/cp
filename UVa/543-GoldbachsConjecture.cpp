#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define int long long
#define pii pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vi>
#define endl "\n"
#define srt(x) sort(x.begin(), x.end())
#define pq priority_queue
#define loop(i, a, b) for (int i = a; i < b; i++)

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
   // make prime sieve upto 10^6

  int n = 1e6 + 1;
  vector<bool> is_prime(n, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i < n; i++)
  {
    if (is_prime[i])
    {
      for (int j = i * i; j < n; j += i)
      {
        is_prime[j] = false;
      }
    }
  }
  vector<int> primes;
  for (int i = 2; i < n; i++)
  {
    if (is_prime[i])
    {
      primes.push_back(i);
    }
  }
  int m;
  while(1){
    cin >> m;
    if (m == 0)
      break;
    int p1=0,p2=0;
    for (int i = 0; i < primes.size(); i++)
    {
      if(m-primes[i] > 0 && is_prime[m-primes[i]]){
        p1=primes[i];
        p2=m-primes[i];
        break;
      }
    }
    if(p1==0 && p2==0){
      cout  << "Goldbach's conjecture is wrong." << endl;
    }else{
      cout << m << " = " << p1 << " + " << p2 <<   endl;
    }
    
  }



  

  return 0;
}
