#include <bits/stdc++.h>
using namespace std;
string rton(string s) {
    // Write your code here
     int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
         if(s[i]=='I'){if(i!=n-1 && (s[i+1]=='V'||s[i+1]=='X')){ans--;}else{ans++;}}
         else if(s[i]=='V'){ans+=5;}
         else if(s[i]=='X'){if(i!=n-1 && (s[i+1]=='L'||s[i+1]=='C')){ans-=10;}else{ans+=10;}}
         else if(s[i]=='L'){ans+=50;}
         else if(s[i]=='C'){if(i!=n-1 && (s[i+1]=='D'||s[i+1]=='M')){ans-=100;}else{ans+=100;}}
         else if(s[i]=='D'){ans+=500;}
         else{ans+=1000;}
        }
        string temp="";
        while(ans){
            int rem=ans%10;
            temp=(char)(rem+'0')+temp;
            ans=ans/10;
        }
        return temp;
}
string ntor(string s){
      int num=0;int pow=1;
      for(int i=s.size()-1;i>=0;i--){
        num=(s[i]-'0')*pow+num;
       pow*=10;
      }string temp="";
     pair<int,string>hash[]={{1000,"M",},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
     for(int i=0;i<13;i++){
        while(num>=hash[i].first){
            temp+=hash[i].second;
            num-=hash[i].first;
        }
     }
     return temp;
}
int main(){
    string input;
    while(cin>>ws>>input){string ans;
        if(input[0]>='0'&&input[0]<='9'){
            
            ans=ntor(input);
        }else{
           ans=rton(input);
        }
         cout<<ans<<'\n';
    }
    return 0;
}