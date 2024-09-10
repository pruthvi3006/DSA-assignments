#include<iostream>
using namespace std;
class item{
    public:
        string name;
        int stockLevel;
        string recorderDate;
        string category;
        item():name(""),stockLevel(0),recorderDate(""),category(""){}
        item(string n, int s,string r,string c):name(n),stockLevel(s),recorderDate(r),category(c){}
        void printitem() const{
            cout<<"Name:"<<name
                <<"Stock Level:"<<stockLevel
                <<"Recorder Date:"<<recorderDate
                <<"Category:"<<category
                <<endl;
        }
};
int partition(item items[], int low, int high){
    int pivot=items[high].stockLevel;
    int i=low-1;
    for(int j=low;j<high;j++){
        if(items[j].stockLevel<pivot){
            i++;
            swap(items[i],items[j]);
        }
    }
    swap(items[i+1],items[high]);
    return i+1;
}
void quickSort(item items[], int low, int high){
}
void merge(item items[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    item*L=new item[n1];
    item*R=new item[n2];
    for(int i=0;i<n1;i++)
    L[i]=items[left+1];
    for(int j=0;j<n2;j++)
    R[j]=items[mid+1+j];
    int i=0,j=0,k=left;
    while(i<n1&&j<n2){
        if(L[i].recorderDate<=R[j].recorderDate){
            items[k]=L[i];
            i++;
        }else{
            items[k]=R[j];
            j++;
        }
        k++;
        while(i<n1){
            items[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            items[k]=R[j];
            j++;
            k++;
        }
        delete[] L;
        delete[] R;
        }
}
        void mergeSort(item items[], int left, int right){
            if(left<right){
                int mid=left+(right-left)/2;
                mergeSort(items,left,mid);
                mergeSort(items,mid+1,right);
                merge(items,left,mid,right);
            }
        }
void shellSort(item items[], int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            item temp=items[1];
            int j;
            for(j=1;j>=gap&&items[j-gap].category>temp.category;j-=gap){
                items[j]=items[j-gap];
            }
            items[j]=temp;
            }
        }
}
    int main(){
            item inventory[]={
                item("Item1",12,"2022-10-2","Grocery"),
                item("Item2",2,"2022-08-3","Shopping"),
                item("Item3",10,"2022-09-20","Stationary"),
            };
            int n=sizeof(inventory)/sizeof(inventory[0]);
            quickSort(inventory,0,n-1);
            cout<<"Sorted by Stock Level(Quick Sort):\n";
            for(int i=0;i<n;i++){
                inventory[i].printitem();
            }
            mergeSort(inventory,0,n-1);
            cout<<"\nSorted by Recorder Date(Merge Sort):\n";
            for(int i=0;i<n;i++){
                inventory[i].printitem();
            }
            return 0;
        }
