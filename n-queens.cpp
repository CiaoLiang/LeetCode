class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int row = 1;
        vector<int> y(n+1);
        vector<vector<string>> ret;
        vector<string> temp;
        while(row>0){
            y[row]++;
            while((y[row]<=n) && (!check(row,y))) y[row]++;
            if(y[row]<=n){
                if(row==n){
                    storeRet(ret,temp,y,n);
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
    void storeRet(vector<vector<string> > &ret,vector<string>temp,vector<int> y,int n){
        string a;
        for(int i=0;i<n;++i){
            a+='.';
        }
        for(int i=0;i<n;++i){
            temp.push_back(a);
        }
        for( int i=1; i<=n; i ++ )
        {
            for( int j=1; j<=n; j++ )
            if( j==y[i] ) temp[i-1][j-1]='Q';
        }
        ret.push_back(temp);
    }
};