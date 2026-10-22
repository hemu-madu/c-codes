#include<stdio.h>
void swap(int arr[],int n){
    for(int i=0;i<n-1;i+=2){
        int temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
    }
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
    swap(arr,n);
    printf("Swapped array:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}