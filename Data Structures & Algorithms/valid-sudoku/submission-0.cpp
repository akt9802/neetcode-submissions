class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(isValid(i,j,board) == false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row,int col,vector<vector<char>>& board){

        if(board[row][col] == '.')  return true;
        // 3 conditions we have to check to satisfy this is working or not
        for(int i=0;i<9;i++){
            // iterating over col
            if(col!=i && board[row][i] == board[row][col])  return false;

            // iterating over row
            if(row!=i && board[i][col] == board[row][col])  return false;
            int x = 3*(row/3)+i/3;
            int y = 3*(col/3)+i%3;
            if(x != row && y != col && board[x][y] == board[row][col])  return false;
        }
        return true;
    }
};
