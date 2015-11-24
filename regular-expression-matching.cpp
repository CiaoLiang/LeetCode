class Solution {
public:
    bool isMatch(string s, string p) {
        if ( p.empty() ) return s.empty();
        if ( p[1]!='*' )
        {
            return ( s[0]==p[0] || (p[0]=='.' && !s.empty()) ) && isMatch(s.substr(1), p.substr(1));
        }
        int i = 0;
        for ( ; s[i]==p[0] || (p[0]=='.' && i<s.size()); ++i)
        {
            if (isMatch(s.substr(i), p.substr(2))) return true; 
        }
        return isMatch(s.substr(i), p.substr(2));
    }
};