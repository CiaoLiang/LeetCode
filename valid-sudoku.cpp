class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<map<char,int>> Sudoku(27);
        for(int i=0;i<9;++i){ //行相等判断
            for(int j=0;j<9;++j){
                if(board[i][j]=='.')
                    continue;
                if(board[i][j]>'9'||board[i][j]<'0')
                    return false;
                if((Sudoku[i])[board[i][j]]>0)
                    return false;
                (Sudoku[i])[board[i][j]]++;
            }
        } 
        
         for(int i=0;i<9;++i){//列相等判断
            for(int j=0;j<9;++j){
                if(board[j][i]=='.')
                    continue;
                if((Sudoku[i+9])[board[j][i]]>0)
                    return false;
                (Sudoku[i+9])[board[j][i]]++;
            }
        }
        
        int it=0;
        while(it<9){
            for(int i=(it%3)*3;i<(it%3)*3+3;++i){
                for(int j=(it/3)*3;j<(it/3)*3+3;++j){
                     if(board[i][j]=='.')
                        continue;
                     if((Sudoku[it+18])[board[i][j]]>0)
                        return false;
                     (Sudoku[it+18])[board[i][j]]++;
                }
            }
            ++it;
        }
        return true;
    }
};