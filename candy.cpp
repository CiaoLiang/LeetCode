class Solution {
public:
    int candy(vector<int> &ratings) {
        int ans=0;
        int size=ratings.size();
        vector<int> ret1(ratings.size(),1);
        ret1[0] = 1;
        ret1[size-1] = 1;
        vector<int> ret2 = ret1;
        for(auto i=1;i<size;++i){
            ret1[i]=ratings[i]>ratings[i-1]?ret1[i-1]+1:1;
            ret2[size-i-1]=ratings[size-i-1]>ratings[size-i]?ret2[size-i]+1:1;
        }
        for(auto i=0;i<size;++i){
            ans+=ret1[i]>ret2[i]?ret1[i]:ret2[i];
        }
        return ans;
    }
};