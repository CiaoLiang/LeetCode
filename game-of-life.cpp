class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                int Num = NumberOfLive(board,i,j);
                if(board[i][j]==1){
                    if(Num<2)
                        board[i][j]=3;
                    if(Num==2||Num==3)
                        board[i][j]=1;
                    if(Num>3)
                        board[i][j]=3;
                }
                if(board[i][j]==0){
                    if(Num==3)
                        board[i][j]=2;
                }
            }
        }
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j]==3)
                    board[i][j]=0;
                else if(board[i][j]==2)
                    board[i][j]=1;
            }
        }
    }
    int NumberOfLive(vector<vector<int>>& board,int i,int j){
        int ret = 0;
        for(int row=i-1; row<=i+1; ++row){
            for(int col = j-1; col<=j+1; ++col){
                if(row<0||row>board.size()-1||col<0||col>board[0].size()-1||(row==i&&col==j))
                    continue;
                if(board[row][col]==1||board[row][col]==3)
                    ++ret;
            }
        }
        return ret;
    }
};