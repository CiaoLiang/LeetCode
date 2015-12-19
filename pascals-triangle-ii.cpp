class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret ={1};
         for(int i=0; i<rowIndex; ++i){
            vector<int> temp = ret;
            temp.push_back(0);
            ret.push_back(0);
            for(int j=1; j<i+2; ++j){
                ret[j]=temp[j-1]+temp[j];
            }
        }
        return ret;
    }
};