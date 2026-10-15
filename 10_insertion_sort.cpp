#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&key<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[100];
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    cout<<"Enter the array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    cout<<"The sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}