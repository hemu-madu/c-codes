#include<stdio.h>
int missing(int arr[],int n){
    for(int i=0;i<n;i++){
        while(arr[i]>0 && arr[i]<=n && arr[arr[i]-1]!=arr[i]){
            int temp=arr[i];
            arr[i]=arr[temp-1];
            arr[temp-1]=temp;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}
int main(){
    int n;
    printf("Enter n value:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int missing_number=missing(arr,n);
    printf("%d\n",missing_number);
    return 0;
}