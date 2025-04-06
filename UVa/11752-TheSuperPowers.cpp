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
  for (long long i = 2; i*i <= n; i++)
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
unsigned long long binpow(unsigned long long a, unsigned long long b)
{
  unsigned long long res = 1;
  while (b > 0)
  {
    if (b & 1)
      res = (res * a) ;
    a = (a * a) ;
    b >>= 1;
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

 sieve(1<<6); 

 set<unsigned long long> st;
 st.insert(1);
 for(int base=2;base<=(1<<16);base++){
     for(int i=4;i<=64;i++){
          if(is_prime[i])continue;
          if(i*log2(base)>=64)break;
          unsigned long long num=binpow(base,i);
          st.insert(num);
     }
   }
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<endl;
    }
    


  return 0;
}
