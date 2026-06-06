class Solution {
public:
    bool isSafe(vector<vector<char>>& board,char digit,int row,int col){
        for(int i =0;i<board[0].size();i++){
            if(board[row][i]==digit) return false;
        }
        for(int i =0;i<board.size();i++){
            if(board[i][col]==digit) return false;
        }
        int strow = (row/3)*3;
        int stcol = (col/3)*3;
        for(int i =strow;i<strow+3;i++){
            for(int j =stcol;j<stcol+3;j++){
                if(board[i][j]==digit) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){

    for(int row=0; row<9; row++){

        for(int col=0; col<9; col++){

            if(board[row][col]=='.'){

                for(char digit='1'; digit<='9'; digit++){

                    if(isSafe(board,digit,row,col)){

                        board[row][col]=digit;

                        if(solve(board))
                            return true;

                        board[row][col]='.';
                    }
                }

                return false;
            }
        }
    }

    return true;
}
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};