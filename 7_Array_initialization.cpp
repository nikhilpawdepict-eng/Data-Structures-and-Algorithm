#include<iostream>
using namespace std;
int main(){
    int arr[100];
    cout<<"Enter the size of the array : ";
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Enter "<<i+1<<"th element : ";
        cin>>arr[i];
    }
    cout<<"Diplay elements : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
       
    }
}