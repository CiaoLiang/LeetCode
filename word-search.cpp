class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(board,i,j,word.c_str()))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >&board,int m,int n,const char *it){
        if(m<0||n<0||m>board.size()-1||n>board[0].size()-1||board[m][n]!=*it)
            return false;
        if(board[m][n]==*it&& *(it+1)=='\u005C0')
            return true;
        char temp = board[m][n];
        board[m][n] = '0';
        if(dfs(board,m-1,n,it+1)||dfs(board,m+1,n,it+1)||dfs(board,m,n+1,it+1)||dfs(board,m,n-1,it+1))
        {
            return true;
        }
        board[m][n] = temp;
        return false;
    }
};