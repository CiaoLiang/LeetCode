class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));  
        int colmin = 0;  
        int colmax = n-1;  
        int rowmin = 0;  
        int rowmax = n-1;  
        int i=0;  
        int j=0;  
        int flag = 0; //走路顺序 
        int number = 1;
        while(rowmin<=rowmax&&colmin<=colmax){  
            if(flag==0){  
                for(j=rowmin; j<=rowmax; ++j){  
                    matrix[i][j] = number;  
                    ++number;
                }
                j = rowmax; //漏掉这个会出错，因为j会走到rowmax+1  
                ++colmin;  
                flag = 1;  
                continue;  
            }  
            if(flag == 1){  
                for(i=colmin; i<=colmax; ++i){  
                    matrix[i][j] = number; 
                    ++number;
                }
                i = colmax;  
                --rowmax;  
                flag = 2;  
                continue;  
            }  
            if(flag == 2){  
                for(j=rowmax; j>=rowmin;--j){  
                    matrix[i][j] = number;
                    ++number;
                }
                j = rowmin;  
                --colmax;  
                flag = 3;  
                continue;  
            }  
            if(flag == 3){  
                for(i=colmax ; i>=colmin; --i){  
                    matrix[i][j] = number;  
                    ++number;
                }
                i = colmin;  
                ++rowmin;  
                flag = 0;  
                continue;  
            }  
        }  
        return matrix;  
    }
};