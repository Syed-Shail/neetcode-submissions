class Solution {
public:
    void trav(vector<vector<char>>& board , int i , int j){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!='O')return;
        board[i][j]='A';
        trav(board,i+1,j);
        trav(board,i-1,j);
        trav(board,i,j+1);
        trav(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0 ; i<board.size() ; i++){
            if(board[i][0]=='O')trav(board,i,0);
            if(board[i][m-1]=='O')trav(board,i,m-1);
        }
        for(int j=0 ; j<m ; j++){
            if(board[0][j]=='O')trav(board,0,j);
            if(board[n-1][j]=='O')trav(board,n-1,j);
        }
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='A')board[i][j]='O';
            }
        }
    }
};
