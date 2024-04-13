#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;
    while(t--){
        string s;cin>>s;
        int ans=0;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {if(s[i]=='\\')st.push(i);
        else if (s[i]=='/'){
            if(!st.empty())
            {ans+=i-st.top();
            st.pop();}
        }}
        cout<<ans<<'\n';
    }
    return 0;
}