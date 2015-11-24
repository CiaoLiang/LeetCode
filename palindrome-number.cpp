class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        if(x<10)
        return true;   //exception 
        int div = 1;
        int temp = x;
        while(temp>9)
        {
            temp = temp/10;
            div = div*10;   //div 
        }
        while(x) //cannot use x>9
        {
            int right = x/div;
            int left = x%10;
            x = (x-right*div)/10; //important cannot use x = (x%div)/10;
            div = div /100;
            if(right!=left)
            return false;
        }
        return true;
    }
};