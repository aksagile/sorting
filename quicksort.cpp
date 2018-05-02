#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;

}
int partition(int arr[],int l, int r){
    int pi=l-1;
    int pivot=arr[r];
    for(int i=l;i<r;i++){
        if(arr[i]<=pivot){
            pi++;
            swap(&arr[i],&arr[pi]);
        }
    }
    swap(&arr[pi+1 ], &arr[r]);
    return (pi + 1);
    
}

void quicksort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int pindex=partition(arr,l,r);
    
    quicksort(arr,0,pindex-1);
    quicksort(arr,pindex+1,r);
    
}

int main(){
    //int arr[] = {2,6,3,8,3,1,88,2,5,65};
    //int n= 10;
    int arr[]={9,1,4};
    int n=3;
    quicksort(arr,0,n-1);
    
    
    for( int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}