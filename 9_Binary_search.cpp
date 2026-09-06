#include<iostream>
using namespace std;
int binary_search(int arr[],int n,int search_ele){
    int Low,Mid,High;
    Low=0;
    High=n-1;
    
    while(Low<=High){
        Mid=(Low+High)/2;
        if(arr[Mid]==search_ele){
            return Mid+1;
        }
        else if(arr[Mid]<search_ele){
            Low=Mid+1;
        }
        else{
            High=Mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[100];
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    cout<<"Enter the sorted array : \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int search_ele;
    cout<<"Enter the searching element : ";
    cin>>search_ele;
    int location =binary_search(arr,n,search_ele);
    cout<<"The element is at "<<location<<" position.";
}