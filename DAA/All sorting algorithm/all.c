#include<stdio.h>
// insertion sort code 1:
int Insertion_sort_1(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j>0;j--){
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}
// insertion sort code 2:
int Insertion_sort_2(int arr[],int n){
    int key,j;
    for(int i=1;i<n-1;++i){
        key=arr[i];
        j=i-1;
        while(arr[j]>key && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
// selection sort :
int Selection_sort(int arr[],int n){
    
}

int main(){
    int arr[]={5,4,3,2,1};
    int n=5;
    Insertion_sort_1(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}