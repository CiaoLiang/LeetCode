class Solution {
public:
    int totalNQueens(int n) {
        int row = 1;
        int ret = 0;
        vector<int> y(n+1);
        while(row>0){
            y[row]++;
            while((y[row]<=n) && (!check(row,y))) y[row]++;
            if(y[row]<=n){
                if(row==n){
                    ret++;
                }
                else row++;
            }
            else{
                y[row]=0;
                row -- ;//回溯
            }
        }
        return ret;
    }
     
    bool check(int k,vector<int> y) { 
        for(int j = 1;j < k;j++)
            if((abs(k-j) == abs(y[j] - y[k]))||(y[j] == y[k])) 
                return false;
        return true;
    }
};