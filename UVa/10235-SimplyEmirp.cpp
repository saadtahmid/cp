#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;
vector<bool> is_prime;
vector<int> primes;
void sieve(int n)
{
  is_prime.resize(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (long long i = 2; i  <= n; i++)
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

  sieve(1000000);
  int n;
  while(cin>>n){
    if(!is_prime[n]){
      cout<<n<<" is not prime.\n";
      continue;
    }
    else{
      //reverse the number
      int rev = 0, temp = n;
      while(temp > 0){
        rev = rev * 10 + temp % 10;
        temp /= 10;
      }
      //check if the reversed number is prime
      if(is_prime[rev]&& rev != n){
        cout<<n<<" is emirp.\n";
      }
      else{
        cout<<n<<" is prime.\n";
      }
    }
  }

  return 0;
}
