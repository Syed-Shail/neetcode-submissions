class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
         for(int i =0 ; i<9; i++){
            unordered_set <char> set1;
            for(int j=0 ;j<9 ; j++ ){
                if(board[i][j]=='.'){
                    continue;
                }
                if(set1.find(board[i][j])!=set1.end()){
                    return false;
                }
                else{
                    set1.insert(board[i][j]);
                }
            }
        }
        for(int i =0 ; i<9; i++){
            unordered_set <char> set1;
            for(int j=0 ;j<9 ; j++ ){
                if(board[j][i]=='.'){
                    continue;
                }
                if(set1.find(board[j][i])!=set1.end()){
                    return false;
                }
                else{
                    set1.insert(board[j][i]);
                }
            }
        }
        for(int blockRow = 0; blockRow < 3; blockRow++) {
    for(int blockCol = 0; blockCol < 3; blockCol++) {
        unordered_set<char> set1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                char num = board[blockRow * 3 + i][blockCol * 3 + j];
                if(num == '.') continue;
                if(set1.find(num) != set1.end()) return false;
                set1.insert(num);
            }
        }
    }
}
    return true;
    }
};
