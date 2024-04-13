#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    while (cin>>n)
    {
       int s=1;
       for(int i=1;i<=n;i++){
        s*=2;
       }
       vector<int>v(s);
       for(int i=0;i<s;i++){
        cin>>v[i];
       }vector<ll>suma(s);
       for(int i=0;i<s;i++){
        int p=i;ll sum=0;
        for(int j=0;j<n;j++){
            int nbr=i^(1<<j);
            sum+=v[nbr];
        } suma[i]=sum;     };ll maxi=-1;
        for(int i=0;i<s;i++){
        int p=i;ll sum=0;
        for(int j=0;j<n;j++){
            int nbr=i^(1<<j);
            sum=suma[i]+suma[nbr];if(sum>maxi)maxi=sum; 
        }     }
        cout<<maxi<<'\n';
    }
    
    return 0;
}