class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int depth = 0;
        int m = matrix.size();
        if(m==0)    return 0;
        int n = matrix[0].size();
        vector<vector<int>> visited(m,vector<int>(n,1));
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j){
                depth = max(depth,Dfs(matrix,visited,i,j));
            }
        return depth;
    }
    
    int Dfs(vector<vector<int>>& matrix,vector<vector<int>>& visited,int x,int y){
        int height = matrix.size();
        int width = matrix[0].size();
        if(visited[x][y]>1)
            return visited[x][y];
        int result = 1;
        int Cur = matrix[x][y];
        int nx,ny = 0;
        for(int i=0; i<4; ++i){
            if(i==0) { nx = x-1; ny = y;}
            if(i==1) { nx = x+1; ny = y;}
            if(i==2) { nx = x; ny = y-1;}
            if(i==3) { nx = x; ny = y+1;}
            if(nx<0||nx>=height||ny<0||ny>=width||matrix[nx][ny]<=matrix[x][y]) continue;//非搜寻的解
            result = max(result, Dfs(matrix,visited,nx,ny)+1);   //超时
            visited[x][y] = result;
        }
        return result;
    }
};
  