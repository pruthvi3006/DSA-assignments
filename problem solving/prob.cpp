#include<iostream>
using namespace std;

class inventory{
    public:
    string name;
    int stock;
    int days;
    int category;

    void getdata(){
        cout<<"Enter the name of product"<<endl;
        cin>>name;
        cout<<"Enter the amount of stock present"<<endl;
        cin>>stock;
        cout<<"Enter the no. of days left to reorder"<<endl;
        cin>>days;
        cout<<"Enter the category"<<endl;
        cout<<"1-Pharma , 2-Stationary ,3-Sports, 4-Grocery, 5-Automobile"<<endl;
               
        cin>>category;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Stock: "<<stock<<endl;
        cout<<"Date: "<<days<<endl;
        cout<<"Category: "<<category<<endl;
    }
};
    void sortWithStock(inventory arr[],int f,int l){
       if(f<l){
     int pivot=f;
     int i=f+1;
     int j=l;
     while(i<j){
        while(arr[i].stock<arr[pivot].stock){
            i++;
        }
        while(arr[j].stock>arr[pivot].stock){
            j--;
        }
        if(i<j){
            inventory temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        
        }
        else{
            break;
        }

     }
     inventory temp=arr[j];
     arr[j]=arr[pivot];
     arr[pivot]=temp;
     sortWithStock(arr,f,j-1);
     sortWithStock(arr,j+1,l);
   }
    }
    
    



   void sortWithDate(inventory arr[],int f,int l){
      if(f<l){
     int pivot=f;
     int i=f+1;
     int j=l;
     while(i<j){
        while(arr[i].days<arr[pivot].days){
            i++;
        }
        while(arr[j].days>arr[pivot].days){
            j--;
        }
        if(i<j){
            inventory temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        
        }
        else{
            break;
        }

     }
     inventory temp=arr[j];
     arr[j]=arr[pivot];
     arr[pivot]=temp;
     sortWithDate(arr,f,j-1);
     sortWithDate(arr,j+1,l);
   }
    }
    
    

    

   void sortWithCategory(inventory arr[], int n){


    int intvl = n / 2;
    for (int gap = intvl; gap >= 1; gap /= 2)
    {
        for (int j = gap; j <= n - 1; j++)
        {
            for (int i = j - gap; i >= 0; i -= gap)
            {
                if (arr[i + gap].category > arr[i].category)
                {
                    break;
                }
                else
                {
                    inventory temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                }
            }
        }
    }
    
}


void drivercode(){
    int n;
    cout<<"Enter the amount of entries"<<endl;
    cin>>n;
    int f=0;
    int l=n-1;

    inventory arr[n],ob;
    int choice;
    do{
       cout << "1.Get data" << endl;
        cout << "2.Display data" << endl;
        cout << "3.Sort according to stock level" << endl;
        cout << "4.Sort according to days left to reorder" << endl;
        cout << "5.Sort accoerding to category number" << endl;
        cout<<"6.Exit"<<endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        switch(choice){
            case 1:
             for(int i=0;i<n;i++){
                arr[i].getdata();
             }
             break;

            case 2:
              for(int i=0;i<n;i++){
                arr[i].display();
              }
              break;

            case 3:
               sortWithStock(arr,f,l);
                for(int i=0;i<n;i++){
                arr[i].display();
              }
               break;
            case 4:
               sortWithDate(arr,f,l);
                for(int i=0;i<n;i++){
                arr[i].display();
              }
               break;
            case 5:
               sortWithCategory(arr,n);
                for(int i=0;i<n;i++){
                arr[i].display();
              }
               break;
            case 6:
              break;

            default:
              break; 
        }

    }while(choice!=6);
}
    
int main(){
    drivercode();
}
   