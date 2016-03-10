class Solution {
    void mark_visited(vector<vector<char>>& board, int x, int y) 
     { 
            int m = board.size(); 
            int n = board[0].size(); 
            board[x][y]='?';
    
               if (x > 1 && board[x - 1][y] == 'O') mark_visited(board, x - 1, y);  // prevent stack overflow error
               if (x < m - 2 && board[x + 1][y] == 'O') mark_visited(board, x + 1, y);
               if (y > 1 && board[x][y - 1] == 'O')  mark_visited(board, x, y - 1);
               if (y< n - 2 && board[x][y+ 1] == 'O')  mark_visited(board, x, y + 1);
          } 
    
    public: void solve(vector<vector<char>>& board) {
    
     if (board.size() == 0) return; 
    
        int m = board.size();
        int n = board[0].size();
    
        
            for (int i=0; i<m; i++) {
                if (board[i][0] == 'O') {
                     mark_visited(board, i, 0);
                }
                if (board[i][n-1] == 'O') {
                    mark_visited(board, i, n-1);
                }
            }
        
            for (int i=1; i<n-1; i++) {
                if (board[0][i] == 'O') {
                     mark_visited(board, 0, i);
                }
                if (board[m-1][i] == 'O') {
                    mark_visited(board, m-1, i);
                }
            }
        
            for (int i=0; i<m ;i++) {
                for (int j=0; j<n; j++) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == '?') {
                        board[i][j] = 'O';
                    }
                }
            }
        
        }
};
  