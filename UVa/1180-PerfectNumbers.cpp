#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <cmath>
#include <unordered_map>
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

  sieve(1<<18);
  int n;
  cin >> n;
for(int i = 0; i < n; i++){
    int x;char c;
    cin>>x>>c;

    if(x<=18&&is_prime[x]&&is_prime[(1<<x)-1]){
      cout<<"Yes\n";
    }
    else{
      cout<<"No\n";
    }
  }
  return 0;
}
