#include<iostream>
using namespace std;

class node{
  public:
  int val;
  node*next;
  node*prev;

  node(int d){
    val=d;
    next=NULL;
    prev=NULL;
  }
};
class DLL{
    public:
   node*head=NULL;
   void insert_start(int d){
    node*nn=new node(d);
    if(head==NULL){
        head=nn;
        return;
    }
    nn->next=head;
    head->prev=nn;
    head=nn;
   }

   void print(){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
   }  
};
int main(){
    DLL list;
    int d;
    cout<<"Enter the element to be enter"<<endl;
    cin>>d;
    list.insert_start(d);
    list.print();
}


   
