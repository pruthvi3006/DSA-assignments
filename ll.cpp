#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(){
        data=0;
        next=NULL;
    }
    node(int d){
        data=d;
        next=NULL;
    }
};
class LL{
    public:
    node *head;

    void insert_start(int d){
        node *new_node=new node(d);

        if(head==NULL){
            cout<<"List is empty"<<endl;
            head=new_node;
            return;
        }
        else{
            new_node->next=head;
            head=new_node;
        }
    }
    void print(){
        node*temp=new node();
        temp=head;
        while(temp->next!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
    }

    

};
int main(){
    LL list;
    list.insert_start(6);
    list.insert_start(5);
    list.insert_start(11);
    list.print();
}