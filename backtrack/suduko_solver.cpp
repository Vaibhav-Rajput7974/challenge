/*
    create subset of array 
    
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int num,vector<vector<char> > &boa,int row,int col){
        for(int i=0;i<9;i++){
            if(boa[i][col] == num)return false;
        }
        for(int i=0;i<9;i++){
            if(boa[row][i] == num)return false;
        }
        int startRow = row - row % 3,  
        startCol = col - col % 3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(boa[startRow+i][startCol+j] == num)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char> > &board,int row,int col){
        if(row == 8 && col == 9){
            return true;
        }
        if(col == 9){
            row++;
            col=0;
        }
        if(board[row][col] != '.'){
            return solve(board,row,col+1);
        }
        for(int i=1;i<=9;i++){
            if(isSafe('0'+i,board,row,col)){
                board[row][col]=('0'+i);
                if(solve(board,row,col+1)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};