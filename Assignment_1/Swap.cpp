#include<iostream>
using namespace std;

int main()
{
    cout <<"\n\n Swap two numbers :\n";
    cout << "--------------------\n";
    int n1 = 2, n2 = 6, temp;
    cout << "Before Swapping the 1st number is :"<< n1 <<"\n";
    cout << "Before Swapping the 2nd number is :"<< n2 <<"\n";

    temp = n2 ;
    n2 = n1 ;
    n1 = temp;

    cout << "After Swapping the 1st number is :"<< n1 <<"\n";
    cout << "After Swapping the 2nd number is :"<< n2 <<"\n";

}