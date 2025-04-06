#include <iostream>
#include <vector>
using namespace std;
vector<bool> is_prime;
vector<int> primes;
void sieve(int n)
{
  is_prime.resize(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (long long i = 2; i <= n; i++)
  {
    if (is_prime[i])
    {
      for (long long j = i * i; j <= n; j += i)
      {
        is_prime[j] = 0;
      }
      primes.push_back(i);
    }
  }
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);


  sieve(1299709);
  int n;
  while(1){
    cin >> n;
    if (n == 0) break;
    int ans = 0;
   if(is_prime[n]){cout << 0 << endl;continue;}
      
   auto it = lower_bound(primes.begin(), primes.end(), n)-primes.begin();
   cout<< primes[it]-primes[it-1]<<endl;
  }
 

  return 0;
}
