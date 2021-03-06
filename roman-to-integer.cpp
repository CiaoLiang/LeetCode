class Solution {
public:
    int romanToInt(string s) {
            int res = 0;
            int size = s.size();
            int val_i, val_i_plus_1;
            res += romanCharToInt(s[size-1]);
            for (int i = 0; i < size-1; i++) {
                val_i = romanCharToInt(s[i]);
                val_i_plus_1 = romanCharToInt(s[i + 1]);
                if ( val_i < val_i_plus_1) {
                    res -= val_i;
                } else {
                    res += val_i;
                }
            }
            return res;
        }

        inline int romanCharToInt(char c) {
            switch (c) {
                case 'I':   return 1;
                case 'V':   return 5;
                case 'X':   return 10;
                case 'L':   return 50;
                case 'C':   return 100;
                case 'D':   return 500;
                case 'M':   return 1000;
                default:    return 0;
            }
     
    }
};