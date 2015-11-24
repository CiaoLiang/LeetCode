class Solution {
public:
    int trailingZeroes(int n) { //how many 5,10,15,20,25(two zero),125(3 zero),725(4 zero) in a n!
        int zeros = 0;
        while(n!=0)
        {
            zeros += n/5;
            n = n/5;
        }
        return zeros;
    }
};