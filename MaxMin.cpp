#include <iostream>
#include <climits>
using namespace std;

struct Pair{
    int min ;
    int max ;
};

struct Pair findMaxMin(int arr[], int low, int high){
    Pair result, left, right;
    int mid;

    if(low == high){
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }
    if(low == high-1){
        if(arr[low]>arr[high]){
            result.min = arr[high];
            result.max = arr[low];
        }
        else{
            result.min = arr[low];
            result.max = arr[high];
        }
        return result;

    }
    mid = (low + high)/2;
    left = findMaxMin(arr, low, mid);
    right = findMaxMin(arr, mid+1, high);

    if(left.min < right.min)
       result.min = left.min;
    else
       result.min = right.min;
       
    if(left.max > right.max)
       result.max = left.max;
    else
       result.max = right.max;

    return result;
}

int main(){
    int arr[] = {1000, 11, 445, -3, 78,345,56};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    Pair result = findMaxMin(arr, 0, arr_size-1);

    cout<< "Minimum element is: "<<result.min <<endl;
    cout<< "Maximum element is: "<<result.max <<endl;
    return 0;
}