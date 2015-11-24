class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;  
        if(numRows==0) return result;  
    vector<int> tem;  
    tem.push_back(1);  
    result.push_back(tem);  
    if(numRows==1) return result;  
    tem.push_back(1);  
    result.push_back(tem);  
    if(numRows==2) return result;  
    for(int i=2;i<numRows;i++){  
        vector<int> solu(i+1,1);  
        for(int j=1;j<i;j++){  
            solu[j] = result[i-1][j-1]+result[i-1][j];  
        }  
        result.push_back(solu);  
    }  
    return result; 
    }
};