class Solution {
public:
    vector<int> grayCode(int n) {
        int size = 1<<n;
        vector<int> ret;
        ret.resize(size);
        for(int i=0;i<size;i++){
            int temp = i^(i>>1);
            ret[i]=temp;
        }
        return ret;
    }
};