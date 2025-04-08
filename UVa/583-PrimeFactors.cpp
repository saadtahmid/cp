#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <unordered_map>
#define int long long
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
vector<int> prime_factorization(int n)
{
  vector<int> factors;
  for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++)
  {
    if (n % primes[i] == 0)
    {
      while (n % primes[i] == 0)
      {
        factors.push_back(primes[i]);
        n /= primes[i];
      }
    }
  }
  if (n > 1)
    factors.push_back(n);
  return factors;
}
signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  sieve(1e5);
  int n;
  while(1){
    cin >> n;
    if(n == 0) break;
    vector<int> factors = prime_factorization(abs(n));
    if(n<0){
      cout << n << " = -1 x ";
      for(int i=0;i<factors.size();i++){
        cout << factors[i] << (i == factors.size()-1 ? "" : " x ");
      }}
    else{
      cout << n << " = ";
      for(int i=0;i<factors.size();i++){
        cout << factors[i] << (i == factors.size()-1 ? "" : " x ");
      }
    }
    cout << endl;
  }
  
}
