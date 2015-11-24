class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> Set;
        queue<string> bfs;
        bfs.push(s);
        Set.insert(s);
        bool find = false;
        while(!bfs.empty()){
            string top = bfs.front();
            bfs.pop();
            if(isValid(top)){
                result.push_back(top);
                find = true;
            }
            if(find)
                continue; //BFS搜寻到一组解,因为是min不用再继续搜索下去
            for(int i=0;i<top.length();++i){
                if(top[i]!='('&&top[i]!=')'){
                    continue;
                }
                string temp = top.substr(0,i)+top.substr(i+1);
                if(Set.count(temp)==0){
                    Set.insert(temp);
                    bfs.push(temp);
                }
            }
            
        }
        return result;
    }
    
    bool isValid(string s){
        size_t len = s.length();
        int count = 0;
        for(int i=0; i<len; ++i){
            if(s[i]=='('){
                count ++;
            }
            else if(s[i]==')'){
                if(count<=0)
                    return false;
                else
                    count--;
            }
        }
        return count == 0;
    }
};