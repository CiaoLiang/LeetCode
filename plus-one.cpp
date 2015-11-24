class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {   //未考虑前缀0的情况
        int carry = 1;
        int temp = 0;
        for(int i = digits.size() - 1; i >= 0; i--)   
        {
           temp = digits[i];
           digits[i] = (digits[i]+carry)%10;
           carry = (temp+carry)/10;
        }
        if(carry==1)
            digits.insert(digits.begin(), 1);
        return digits;

    }
};