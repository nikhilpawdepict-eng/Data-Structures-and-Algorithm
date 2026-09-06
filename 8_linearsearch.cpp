#include<iostream>
using namespace std;
int linear_search(int arr[],int n,int search_ele){
    for(int i=0;i<n;i++){
        if(arr[i]==search_ele){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int arr[100];
    int n;
    int search_ele;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"Enter the array : ";
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    cout<<"Enter the element you want to search : ";
    cin>>search_ele;
    cout<<"The element is at position "<<linear_search(arr,n,search_ele)<<" in the array.";
}