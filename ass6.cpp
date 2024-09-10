#include<iostream>
using namespace std;
class node{
    public:
    int coff;
    int pow;
    node*next;
    node(){
        coff=0;
        pow=0;
        next=NULL;
    }
    node(int c,int p){
        coff=c;
        pow=p;
        next=NULL;
    }
};
class polynomial{
    public:
    node*head=NULL;

    void creat_node(int x, int y){
     node*nn=new node(x,y);
     if(head==NULL){
        head=nn;
     }
     else{
        node*temp=new node();
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
     }
    }

    void printpoly(){
        if(head!=NULL){
            node*temp=head;
            while(temp->next!=NULL){
                cout<<temp->coff<<"x^"<<temp->pow<<"+";
                temp=temp->next;
            }
            cout<<temp->coff<<"x^"<<temp->pow;
            cout<<endl;
        }
    }
    void add_poly(polynomial l1,polynomial l2){
        node*p1=l1.head;
        node*p2=l2.head;
        node*result=new node();
        node*curr=result;

        while(p1!=NULL && p2!=NULL){
            if(p1->pow==p2->pow){
                node*nn=new node();
                nn->coff=p1->coff+p2->coff;
                nn->pow=p1->pow;
                p1=p1->next;
                p2=p2->next;
                if(curr==NULL){
                    curr=nn;
                }
                else
                curr->next=nn;
                curr=curr->next;

            }
            else if(p1->pow>p2->pow){
                node*nn=new node();
                nn->coff=p1->coff;
                nn->pow=p1->pow;
                p1=p1->next;
                curr->next=nn;
                curr=curr->next;

            }
            else {
                node*nn=new node();
                nn->coff=p2->coff;
                nn->pow=p2->pow;
                p2=p2->next;
                curr->next=nn;
                curr=curr->next;
            }
        }
        while(p1!=NULL){
            node*nn=new node();
            nn->coff=p1->coff;
            nn->pow=p1->pow;
            p1=p1->next;
            curr->next=nn;
            curr=curr->next;
        }
        while(p2!=NULL){
            node*nn=new node();
            nn->coff=p2->coff;
            nn->pow=p2->pow;
            p2=p2->next;
            curr->next=nn;
            curr=curr->next;
        }
        head=result->next;
    }
};
int main(){
    polynomial l1,l2,l3;
    l1.creat_node(15,6);
    l1.creat_node(25,5);
    l1.creat_node(3,2);

    cout<<"First polynomial:"<<endl;
    l1.printpoly();

    l2.creat_node(2,6);
    l2.creat_node(5,4);
    l2.creat_node(8,3);
    cout<<"Second polynomial:"<<endl;
    l2.printpoly();

    l3.add_poly(l1,l2);
    cout<<"Addition polynomial:"<<endl;
    l3.printpoly();


}