#include<bits/stdc++.h>
using namespace std;
bool findPair(int arr[], int size, int n){
    //code
     unordered_map<int, int> map;
    for(int i = 0; i < size; i++){
        map[arr[i]] = i;
    }
    // if(n == 0) return 0;
    
    for(int i = 0; i < size; i++){
        int diff = abs(arr[i] - n);
        if(map.find(diff) != map.end() && map[diff] != i) return true;
    }
    
    return false;
    
}