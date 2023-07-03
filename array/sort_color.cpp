#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void swap(vector<int> &arr,int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
    void sortColors(vector<int>& arr) {
        int n=arr.size();
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high)
        {
            if(arr[mid] == 0)
            {
                swap(arr,low,mid);
                low++;
                mid++;
            }
            else if(arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr,mid,high);
                high--;
            }
        }
    }
};
int_fast32_t main(){
    Solution s;
    vector<int> arr={1,0,1,0,2,1};
    s.sortColors(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}