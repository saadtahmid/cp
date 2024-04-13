#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){string s;
    while(getline(cin,s)){
        stringstream ss;
        ss<<s;int n;
        // {n,how much more can we add}
        stack<pair<int,int>>st;int valid=1;
        while(ss>>n&&valid){
            if(n<0){n=n*-1;
                if(!st.empty()){
                    if(n>=st.top().second)valid=false;
                    else st.top().second-=n;
                }
                st.push({n,n});
            }else{
                if(st.empty()||st.top().first!=n)valid=false;
                else st.pop();
            }
        }if(!st.empty())valid=0;
        cout << ((valid) ? ":-) Matrioshka!\n" : ":-( Try again.\n");
    }

    return 0;
}