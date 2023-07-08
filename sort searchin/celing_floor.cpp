/*
    approch is simple the point where low and mid cross each other is the point where the number may be com
    so the value of low pointer is our celing 
    and value of high pointer is out flor 
    and if they both come out of the limit of array which means ether the flor pointer do not exist or the celing do not exist  
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void find(vector<int> &arr,vector<int> &query){
        int n=arr.size();
        vector<pair<int,int> > ans;
            for(int i=0;i<query.size();i++){
                int target=query[i];
                int low=0;
                int high=n-1;
                int flor=0;
                int celing=0;
                while(low<=high){
                    flor=arr[low];
                    celing=arr[high];
                    int mid=(low+high)/2;
                    if(arr[mid] > target){
                        high=mid-1;
                    }
                    else if(arr[mid] < target){
                        low=mid+1;
                    }
                    else{
                        ans.push_back({arr[mid],arr[mid]});
                        break;
                    }
                if(low < n && high >= 0  && low > high){
                    ans.push_back({arr[high],arr[low]});
                }
                else if(low >= n){
                    ans.push_back({flor,INT_MAX});
                }
                else if(high < 0){
                    ans.push_back({INT_MIN,celing});
                }
                }
            }
            for(int i=0;i<ans.size();i++){
                cout<<ans[i].first<<"  "<<ans[i].second<<endl;
            }
        }
};
int main(){
    Solution s;
    vector<int> arr={1, 2, 8, 10, 10, 12, 19};
    vector<int> q={0,1,5,20,3,6,12,-1};
    s.find(arr,q);
    
    return 0;
}