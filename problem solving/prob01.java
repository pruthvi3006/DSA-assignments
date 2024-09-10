

public class prob01 {
    static void sort(int arr[],int n){
        int i=0;
        int j=n-1;
        while(i<j){
        while(i<j && arr[i]<0){
            i++;
        }
        while(i<j && arr[j]>0){
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;

        }
    }
    }
    static void display(int arr[],int n){
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static void main(String[] args) {
        int arr[]={9, -3, 5, -2, -8, -6, 1, 3};
        int n=arr.length;
        sort(arr,n);
        display(arr, n);
    }
}
