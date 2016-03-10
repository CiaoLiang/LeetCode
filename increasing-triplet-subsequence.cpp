class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=3)
            return false;
        int Len = 1;
        vector<int> Len_Min(4,0);
        Len_Min[1] = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(nums[i]>Len_Min[Len]){
                Len++;
            if(Len>=3)
                return true;
            Len_Min[Len] = nums[i];
            }
            else{//untill nums[i]<Len_Min[k],replace the min one.
                int k = Len;
                while(k>=1 && nums[i]<=Len_Min[k]) k--;
                Len_Min[k+1] = nums[i]; 
            }
        }
        if(Len<3)
            return false;
    }
};
  