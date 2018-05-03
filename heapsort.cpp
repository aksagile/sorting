#include <iostream>
using namespace std;
void heapify(int arr[],int n, int i){
    int max = i;
    int l= 2*i+1;
    int r=2*i+2;
    if(l<n&&arr[max]<=arr[l]){
        max = l;
    }
    if(r<n&&arr[max]<=arr[r]){
        max=r;
    }
    if(max!=i){
        swap(arr[max],arr[i]);
        heapify(arr,n,max);
    }
}
void heapsort( int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main() {
    int arr[] = {2,6,3,8,3,1,88,2,5,65};
    int n= 10;

    heapsort(arr,n);
    for( int i=0;i<n;i++){
    cout<<arr[i]<<" ";}
}