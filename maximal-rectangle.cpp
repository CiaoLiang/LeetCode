class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col = matrix.size();
        if(col==0)
            return 0;
        int row = matrix[0].size();
        int res = 0;
        for(int j=0; j<row; ++j){
            int flag = 0;
            for(int i=0; i<col; ++i){
                if(matrix[i][j]=='1'){
                    flag++;
                    matrix[i][j]='0'+flag;
                }
                else if(matrix[i][j]=='0'){
                    flag = 0;
                }
            }
        }
        for(int i=0; i<col; ++i){
            int temp = largestRectangleArea(matrix[i]);
            res = res>temp?res:temp;
        }
        return res;
    }
    int largestRectangleArea(vector<char>& height) {
       stack<int> index;
       stack<char> h;
       if(height.size()==0)
            return 0;
       index.push(0);
       h.push(height[0]);
       int area = 0;
       for(int i=1; i<height.size(); ++i){
           if(h.empty()||height[i]>h.top()){
               index.push(i);
               h.push(height[i]);
           }
           else if(height[i]<h.top()){
               int tempIdx = 0;
               while(!h.empty() && height[i]<=h.top()){
                  tempIdx = index.top();
                  area = area>(i-index.top())*(h.top()-'0')?area:(i-index.top())*(h.top()-'0');
                  h.pop();
                  index.pop();
               }
               index.push(tempIdx);
               h.push(height[i]);
           }
       }
       while(!h.empty()){
           area = area >(height.size()-index.top())*(h.top()-'0')? area:(height.size()-index.top())*(h.top()-'0');
           h.pop();
           index.pop();
       }
       return area;
    }
};