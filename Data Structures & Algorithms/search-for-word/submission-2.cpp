class Solution {
public:
    bool trav(vector<vector<char>>& board , string& word, int i , int j , int n){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        
        if(board[i][j] != word[n]) return false;

        if(n == word.size()-1) return true;

        char temp = board[i][j];
        board[i][j] = '#'; 

        bool found =
            trav(board, word, i+1, j, n+1) ||
            trav(board, word, i-1, j, n+1) ||
            trav(board, word, i, j+1, n+1) ||
            trav(board, word, i, j-1, n+1);

        board[i][j] = temp; 

        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for(int i=0 ; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ;j++){
                if(board[i][j]==word[0]){
                    res= res || trav(board,word,i,j,0);
                }
            }
        }
        return res;
    }
};
