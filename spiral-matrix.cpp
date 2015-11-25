class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0)
            return ret;
        int colmin = 0;
        int colmax = matrix.size()-1;
        int rowmin = 0;
        int rowmax = matrix[0].size()-1;
        int i=0;
        int j=0;
        int flag = 0;
        while(rowmin<=rowmax&&colmin<=colmax){
            if(flag==0){
                for(j=rowmin; j<=rowmax; ++j)
                    ret.push_back(matrix[i][j]);
                j = rowmax;
                ++colmin;
                flag = 1;
                continue;
            }
            if(flag == 1){
                for(i=colmin; i<=colmax; ++i)
                    ret.push_back(matrix[i][j]);
                i = colmax;
                --rowmax;
                flag = 2;
                continue;
            }
            if(flag == 2){
                for(j=rowmax; j>=rowmin;--j)
                    ret.push_back(matrix[i][j]);
                j = rowmin;
                --colmax;
                flag = 3;
                continue;
            }
            if(flag == 3){
                for(i=colmax ; i>=colmin; --i)
                    ret.push_back(matrix[i][j]);
                i = colmin;
                ++rowmin;
                flag = 0;
                continue;
            }
        }
        return ret;
    }
};