class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    void dfs(int i,int j,vector<vector<char>>& board){
        board[i][j] = '#';
        for(auto [x,y] :dir){
            int ii = i+x;
            int jj = j+y;
            if(ii>+0 && jj>=0 && ii<board.size() && jj<board[0].size() && board[ii][jj]=='O'){
                dfs(ii,jj,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][board[0].size()-1]=='O') dfs(i,board[0].size()-1,board);
        }
        for(int j = 0;j<board[0].size();j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[board.size()-1][j]=='O') dfs(board.size()-1,j,board);
        }
        for(int i =0;i<board.size();i++){
            for(int j =0;j<board[0].size();j++){
                if(board[i][j]=='#') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] = 'X';
            }
        }
    }
};