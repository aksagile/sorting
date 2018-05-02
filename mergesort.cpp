#include <iostream>
using namespace std;

void merge(int left[],int right[],int m,int n,int arr1[]){
    int i=0,k=0,j=0;
    while(i<m&&j<n){
        if(left[i]>right[j]){
            arr1[k++]=right[j++];
            
        }
        else{
            arr1[k++]=left[i++];
            
        }
    }
    while(i<m){
        arr1[k++]=left[i++];
    }
    while(j<n){
        arr1[k++]=right[j++];
    }

}

void mergesort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int mid=l+((r-l)/2);
    int left[100]={0}, right[100]={0};
    for(int i=0;i<=mid-l;i++){
        left[i]= arr[i];    
    }
    int k=0;
    for(int i=0;i<r-mid;i++){
        right[k++]=arr[i+mid+1];
    }
    mergesort(left,0,mid-l);
    mergesort(right,0,r-mid-1);
    merge(left,right,mid-l+1,r-mid,arr);
}

int main(){
    int arr[] = {2,6,3,8,3,1,88,2,5,65};
    int n= 10;
    
    mergesort(arr,0,n-1);
    
    for( int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


