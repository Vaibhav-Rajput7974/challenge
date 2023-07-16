/*
        In this type of sorting we are going to sort out array according to there every digit place 
        ex :- 
            first for 1 then 10 then 100 

        we are goin to use the count sort for sorting accoring to the digit place
        
*/
#include<bits/stdc++.h>
using namespace std;
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void count(int arr[],int n,int exp){
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1 ]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }

}
int radixsort(int arr[],int n){
    int m=getMax(arr,n);
    for(int i=1; m/i > 0 ;i*=10){
        count(arr,n,i);
    }
}
int main()
{
    int arr[] = { 543, 986, 217, 765, 329 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixsort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    return 0;
}