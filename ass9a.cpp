#include<iostream>
using namespace std;

class Queue{
    public:
    int queue[100];
    int n=100;
    int front=-1;
    int rear=-1;

    void enqueue(int x){
        if(rear > n-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            if(front==-1){
                front=0;

            }
            
            queue[++rear]=x;
           
        }
    }
   void remove(){
      if(front==rear==-1 || front>rear){
        cout<<"Empty queue"<<endl;
      }
      else{
      int val=queue[front];
      front++;
      cout<<"The deleted element is :"<<val<<endl;
      }
   }

   void display(){
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" "<<endl;
    }
   }

   void drivercode(){
     Queue q1;
     int choice;
     do{
     cout<<"1.Add the member in waitlist"<<endl;
     cout<<"2.Delete the member from waitlist"<<endl;
     cout<<"3.Display waitlist"<<endl;
     cout<<"4.Exit"<<endl;
      cout << "Enter your choice: ";
        cin >> choice;

     switch (choice) {
        case 1: 
        int val;
        cout<<"Enter the token number to be entered"<<endl;
        cin>>val;
        q1.enqueue(val);
        break;

        case 2:
        q1.remove();
        break;

        case 3:
        q1.display();
        break;

        case 4: 
        cout<<"Exiting..."<<endl;
        break;

        default:
        cout << "Invalid choice. Please try again." << endl;
                break;
   }
   }
   while(choice!=4);
    
}
};
int main(){
  Queue q1;
//   q1.enqueue(5);
//   q1.enqueue(10);
//   q1.enqueue(10);
// q1.enqueue(10);
// q1.remove();
// q1.remove();
// q1.display();
q1.drivercode();

}