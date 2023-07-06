#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int>  pre_smaller(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while(st.top() != -1 && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> next_smaller(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top() != -1 && arr[i] <= arr[st.top()]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int Histograme(vector<int> &arr){
        vector<int>  pre=pre_smaller(arr);
        vector<int> next=next_smaller(arr);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int cur=(next[i]-pre[i]-1)*arr[i];
            ans=max(ans,cur);
        }
        cout<<ans<<endl;
        return ans;
    }
    int largest_rectangle(vector<vector<int> > &matrix){
        vector<int> cur;
        int ans=0;
        cur=matrix[0];
        ans=max(ans,Histograme(cur));
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]){
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            ans=max(ans,Histograme(matrix[i]));
        }   
        return ans;
    }
};
int main(){
    vector<vector<int> > matrix{
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
    Solution s;
    int ans=s.largest_rectangle(matrix);
    cout<<ans;
    return 0;
}