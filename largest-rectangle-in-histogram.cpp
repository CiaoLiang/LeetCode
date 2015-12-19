class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
       stack<int> index;
       stack<int> h;
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
                  area = area>(i-index.top())*h.top()?area:(i-index.top())*h.top();
                  h.pop();
                  index.pop();
               }
               index.push(tempIdx);
               h.push(height[i]);
           }
       }
       while(!h.empty()){
           area = area >(height.size()-index.top())*h.top()? area:(height.size()-index.top())*h.top();
           h.pop();
           index.pop();
       }
       return area;
    }
};