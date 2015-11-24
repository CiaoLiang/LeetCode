class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0)
            return false;
        stack<char> stk;
        for(int i=0;i<s.size();++i){
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                stk.push(s[i]);
            if(s[i]=='}'||s[i]==']'||s[i]==')'){
                if(stk.size()==0)
                    return false;
                if((s[i]==')'&&stk.top()!='(')||(s[i]=='}'&&stk.top()!='{')||(s[i]==']'&&stk.top()!='['))
                    return false;
                stk.pop();
            }
        }
        if(stk.size()==0)
            return true;
    }
};