#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 class Node {
 public:
  char data;
    Node* next;
      Node() : data(0), next(nullptr) {}
      Node(char x) : data(x), next(nullptr) {}
  };
int main(){string s;while(getline(cin,s))
    {Node *temp=new Node();
    Node* head=temp;Node*tail=temp;Node*curr=tail;
    
    for(int i=0;i<s.size();i++){
        char x=s[i];
        if(x=='['){curr=head;continue;}
        if(x==']'){curr=tail;continue;}
        Node* nd=new Node(x);    
        nd->next=curr->next;
        curr->next=nd;if(curr==tail){
            tail=nd;
        }
        curr=nd;
    }
    curr=head->next;
    while(curr!=NULL){
        cout<<curr->data;
        curr=curr->next;
    }cout<<'\n';}
    return 0;
}