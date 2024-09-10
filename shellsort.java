public class shellsort {
   static  void shellsort(int arr[]){
        int n=arr.length;
        int intvl = n/2;
        for(int gap=intvl;gap>=1;gap/=2){
            for(int j=gap;j<=n-1;j++){
                for(int i=j-gap;i>=0;i-=gap){
                    if(arr[i+gap]>arr[i]){
                        break;
                    }
                    else{
                        int temp=arr[i];
                        arr[i]=arr[i+gap];
                        arr[i+gap]=temp;
                    }
                }
            }

        }
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+ " ");
        }
        
    }
    public static void main(String[] args) {
        int arr []={11,5,117,26,13,70,42,20};
        shellsort(arr);
        
    }
}
