class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(int i=0;i<tokens.size();++i){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                //if(stk.size()<2){
                //    return 0;
               // }
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(tokens[i]=="+") 
                    stk.push(a+b);
                if(tokens[i]=="-")
                    stk.push(a-b);
                if(tokens[i]=="/"){
                   // if(b==0)
                      //  return 0;
                   // else 
                   stk.push(a/b);
                }
                if(tokens[i]=="*") 
                    stk.push(a*b);
                }
            else stk.push(stoi(tokens[i]));
        }
        //if(stk.size()!=1)
           // return 0;
        //else 
            return stk.top();
    }
};