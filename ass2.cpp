#include<iostream>
using namespace std;

class PCCOE{
    public:
    int EmpId;
    string name;
    int salary;

    void getData(){
        cout<<"Enter the employee Id"<<endl;
        cin>>EmpId;
        cout<<"Enter Employee name"<<endl;
        cin>>name;
        cout<<"Enter salary"<<endl;
        cin>>salary;

    }

    void display(){
        cout<<"ID: "<<EmpId<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;

        
    }


   void quicksort(PCCOE arr[],int f,int l){
    if(f<l){
     int pivot=f;
     int i=f+1;
     int j=l;
     while(i<j){
        while(arr[i].EmpId<arr[pivot].EmpId){
            i++;
        }
        while(arr[j].EmpId>arr[pivot].EmpId){
            j--;
        }
        if(i<j){
            PCCOE temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        
        }
        else{
            break;
        }

     }
     PCCOE temp=arr[j];
     arr[j]=arr[pivot];
     arr[pivot]=temp;
     quicksort(arr,f,j-1);
     quicksort(arr,j+1,l);
   }
    }
    
 };




int main(){
    int n;
    cout<<"Enter the no. of employees"<<endl;
    cin>>n;
    PCCOE E[n],ob;
    for(int i=0;i<n;i++){
        E[i].getData();
    }
    int f=0;
    int l=n-1;
    ob.quicksort(E,f,l);
    for(int i=0;i<n;i++){
        E[i].display();
    }

    return 0;

}