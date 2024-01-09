#include <iostream>
using namespace std;

int binarysearch(int arr[], int size, int target){
    int left = 0;
    int right = size-1;

    while(left <= right){
        int mid = (left +right)/2;
        ji
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {78,45,25,8,43,89,46,12};
    int target = 8;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int result = binarysearch(arr, arr_size, target);

    if(result != -1)
       cout<<"Element found at index:"<<result<<endl;
    else
       cout<<"Element not found in the array:"<<endl;

       return 0;
}