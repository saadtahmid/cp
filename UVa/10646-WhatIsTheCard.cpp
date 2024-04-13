#include <bits/stdc++.h>
using namespace std;
int main(){int t;cin>>t;
    for(int i=1;i<=t;i++){
        vector<string>cards;
        for(int i=0;i<52;i++){
            string x;
            cin>>ws>>x;
            cards.push_back(x);
        }int ind=26;int y=0;
        for(int i=0;i<3;i++){int val;
            if(cards[ind][0]>='2'&&cards[ind][0]<='9'){
                val=cards[ind][0]-'0';
            }else val=10;
            int rem=10-val;
            y+=val;
            ind=ind-(rem+1);
        };
        cards.erase(cards.begin()+ind+1,cards.begin()+27);
        cout<<"Case "<<i<<": "<<cards[y-1]<<'\n';
    }
    return 0;
}