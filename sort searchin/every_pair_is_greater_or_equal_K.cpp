#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool isPossible(int a[], int b[], int n, int k)
    {
        sort(a, a + n);
        sort(b, b + n, greater<int>());
 
        for (int i = 0; i < n; i++)
            if (a[i] + b[i] < k)
                return false;
 
        return true;
    }
};
int main(){
    Solution s;
    int a[]={1,2,3,4,7};
    int b[]={8,9,5,4,3,2};
    int n=5;
    int k=10;
    s.isPossible(a,b,n,k);

    return  0;
}