class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0;
        int right = row*col-1;
        while(left<=right){
            int mid = (left+right)/2;
            int i = mid/col;
            int j = mid%col;
            if(matrix[i][j]==target){
                return true;
            }
            if(matrix[i][j]<target){
                left = mid+1 ;
            }
            else if(matrix[i][j]>target){
                right = mid-1; 
            }
        }
        return false;
    }
};