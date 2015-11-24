class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> m;
        set<string> set_string;
        istringstream input(str);
        string s;
        for(int i = 0; i < pattern.size(); i++){
            input>>s;
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != s)return false; //pattern already mapped with some other string
            }
            else {
                if(set_string.count(s)){
                    return false;//string already exist for some pattern char 
                }
                else{
                    m[pattern[i]] = s;
                    set_string.insert(s);
                }
            }
        }
        if(input>>s)return false ;//more string compared to pattern
        return true;
    }
};