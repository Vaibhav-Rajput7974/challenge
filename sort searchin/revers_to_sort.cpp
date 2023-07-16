/*
        we will traverse from front and will find the point where our array is not sorted in incresing order and storre it in our low variable
        similarly we will traverse from the and and will store the point where our array is not sorted in decresing order and store it in high variable 
        now if our low pointer have riched to the index greater than the high pointer which means there is no subarray to sort and our array is already sorted
        else we will sort the array between low and high+1 pointer and will cheak then if the array is sorted return true 
        else 
            false


*/
#include<bits/stdc++.h>
using namespace std;
bool sortArr(int arr[],int n){
    int low=0;
    int high=n-1;
    while(low <= high){
        if(arr[low]<=arr[low+1]){
            low++;
        }
        else if(arr[high]>=arr[high-1]){
            high--;
        }
        else{
            break;
        }
    }
    if(low>high){
        return true;
    }
    else{
        reverse(arr+low,arr+high+1);
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                return false;
            }
        }
        return true;
    }
}
int main()
{
    int arr[] = { 1, 2, 5, 4, 3 ,10,11};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sortArr(arr, n) ? (cout << "Yes" << endl)
                    : (cout << "No" << endl);
    return 0;
}