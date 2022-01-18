#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e9+7;

class node{
   public: 
   int data;
   node* next;
};

node* insert(node* head, int val){
    node* n= new node();
    n->data=val;
    if(head==NULL){
       head=n;
       n->next=NULL;
       return head;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->next=NULL;
    return head;  
}

void display(node *head){
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<"\n";
}

node* rev(node* head,int k){     
node* prev=head;
node* cur=prev->next;     
int c=1;
while(c!=k && cur!=NULL){
node* next=cur->next;
cur->next=prev;
prev=cur;
cur=next;
c++;
}
if(cur!=NULL){
head->next=rev(cur,k);
}
else{
    head->next=NULL;
}
return prev;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
node* head=NULL;
while(n--){
    int val;
    cin>>val;
    head=insert(head,val);
}
int k;
cin>>k;
head=rev(head,k);
display(head);
return 0;
}