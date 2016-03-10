class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> Stack;
        vector<int> data;
        StringToInt(preorder,data);
        Stack.push(data[0]);
        for(int i=1; i<data.size(); ++i){
            if(data[i]==-1){
                while(Stack.size()>=2&&Stack.top()==-1){
                    Stack.pop();
                    if(Stack.top()!=-1)
                        Stack.pop();
                }
                Stack.push(data[i]);
            }
            else
                Stack.push(data[i]);
        }
        if(Stack.size()==1&&Stack.top()==-1)
            return true;
        return false;
    }
    void StringToInt(string preorder,vector<int>&ret){
        int temp = 0;
        for(int i=0; i<preorder.size(); ++i){
            if(preorder[i]=='#')
                temp = -1;
            if(preorder[i]!=','&&preorder[i]!='#'){
                temp = 10*temp + preorder[i]-'0';
            }
            if(i==preorder.size()-1||preorder[i]==','){
                ret.push_back(temp);
                temp = 0;
            }
        }
    }
};
  