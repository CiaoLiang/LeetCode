class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        int ret = INT_MAX;
        for(int i=1; i<height; ++i){
            for(int j=0; j<triangle[i].size(); ++j){
                if(j == 0)
                    triangle[i][j] = triangle[i-1][j]+triangle[i][j];
                else if(j == triangle[i].size()-1)
                    triangle[i][j] = triangle[i-1][j-1]+triangle[i][j];
                else
                    triangle[i][j] = min(triangle[i-1][j]+triangle[i][j],triangle[i-1][j-1]+triangle[i][j]);
            }
        }
        for(int j=0; j<triangle[height-1].size(); ++j){
            ret = min(ret,triangle[height-1][j]);
        }
        return ret;
    }
};