class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(nums == NULL)
        return ;
        k = k%n;
        reverse(nums,n);
        reverse(nums,k);
        reverse(nums+k,n-k);
    }
    
    void reverse(int *nums,int n)
    {
        if(nums == NULL)
        return ;
        int *pBegin = nums;
        int *pEnd = nums+n;
        while(pBegin<pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
            ++pBegin;
            --pEnd;
        }
        
    }
};