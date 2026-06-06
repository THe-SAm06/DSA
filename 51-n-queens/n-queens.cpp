class Solution {
public:
    bool isSafe(vector<string>& board,int n,int i,int col){
        int rw = i;
        int cl = col;
        while(col>=0){
            if(board[i][col]=='Q') return false;
            col--;
        }
        col = cl;
        while(col>=0 && i>=0){
            if(board[i][col]=='Q') return false;
            col--;
            i--;
        }
        col = cl;
        i = rw;
        while(i<n && col>=0){
            if(board[i][col]=='Q') return false;
            col--;
            i++;
        }
        return true;
    }
    void solve(int n,int col,vector<vector<string>>& arr,vector<string>& board){
        if(col>=n){
            arr.push_back(board);
            return;
        }
        for(int i =0;i<n;i++){
            if(isSafe(board,n,i,col)){
                board[i][col]='Q';
                solve(n,col+1,arr,board);
                board[i][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> arr;
        vector<string> board(n, string(n, '.'));
        solve(n,0,arr,board);
        return arr;
    }
};