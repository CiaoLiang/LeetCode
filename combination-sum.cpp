class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> temp;
        
        ret.clear();
        sort(candidates.begin(),candidates.end());
        sum(candidates,0,temp,target);
        return ret;
    }
    void sum(vector<int> &candidates,int idx,vector<int> &temp,int target){
        if(target==0){
            ret.push_back(temp);
        }
        else{
            for(int i=idx;i<candidates.size();++i){
                if(target>=candidates[i]){
                    temp.push_back(candidates[i]);
                    sum(candidates,i,temp,target-candidates[i]);
                    temp.pop_back();
                }
            }
        }
    }
private:
    vector<vector<int> > ret;
};