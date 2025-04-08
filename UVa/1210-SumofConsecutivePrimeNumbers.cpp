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

  sieve(10000);
  vector<int>prefixsum(primes.size() , 0); unordered_map<int, int> mp;
  prefixsum[0] = primes[0];
  for(int i = 1; i < primes.size(); i++){
    prefixsum[i] = prefixsum[i-1] + primes[i];
  }
  for(int i=0;i<prefixsum.size();i++){
    mp[prefixsum[i]] +=1;
    for(int j=0;j<i;j++){
     mp[prefixsum[i] - prefixsum[j]] +=1;
    }
  }
 
  int n;
  while(cin>>n){
    if(n== 0){
      break;
    }
    if(mp[n])cout<<mp[n]<<"\n";
    else cout<<0<<"\n";
  }

  return 0;
}
