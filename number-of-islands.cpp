class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if(grid.size()==0)
            return 0;
        int count = 0;
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                dfs(grid,i,j);
                ++count;
                }
            }
        return count;
    }
    
    void dfs(vector<vector<char>> &grid,int i,int j){
        grid[i][j]='X';
            if(j!=grid[0].size()-1){
                if(grid[i][j+1]=='1')
                dfs(grid,i,j+1);
            }
            if(j!=0){
                if(grid[i][j-1]=='1')
                dfs(grid,i,j-1);
            }
            if(i!=grid.size()-1){
                if(grid[i+1][j]=='1')
                dfs(grid,i+1,j);
            }
            if(i!=0){
                if(grid[i-1][j]=='1')
                dfs(grid,i-1,j);
            }
        }
};