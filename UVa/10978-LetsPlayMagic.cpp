#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){while(1){int n;cin>>n;if(n==0)break;
   vector<string>v(n);int from=-1;
   vector<int>vis(n,0);
   for(int i=0;i<n;i++){
       string a,b;cin>>ws>>a>>b;
      ;int rem=b.size();int cnt=0;
      while(cnt!=rem){from++;from=from%n;
        if(vis[from]==0)cnt++;
      }
       v[from]=a;vis[from]=1;
   }cout<<v[0];
   for(int i=1;i<n;i++){
    cout<<' '<<v[i];
   }cout<<'\n';
   }




    return 0;
}
