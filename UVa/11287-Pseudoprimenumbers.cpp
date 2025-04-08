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
int binpow(int a, int b, int m)
{
  int res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = (res * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return res;
}
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

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  sieve(32000);
  int p,a;
while(1){
  cin>>p>>a;
  if(p==0 && a==0) break;
  bool ok = 0;
  if(p%2==0)ok=1;
  else{
    for(int i=0;i<primes.size();i++){
      if(primes[i]*primes[i]>p)break;
     if(p%primes[i]==0){
        ok=1;
        break;
      }
    }
  }
  if(ok && binpow(a,p,p)==a)cout<<"yes"<<endl;
  else cout<<"no"<<endl;
} 
  return 0;
}
