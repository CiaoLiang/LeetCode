class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> q;
        q.push(beginWord);
        queue<int> dis;
        dis.push(1);
        wordDict.erase(beginWord);
        while(!q.empty()){
            string now = q.front();
            int distance = dis.front();
            if(now==endWord)
                return distance;
            q.pop();
            dis.pop();
            for(int i=0;i<now.size();++i){
                for(char j='a';j<='z';++j){
                    char rec = now[i];
                    now[i] = j;
                    if(wordDict.find(now)!=wordDict.end())
                    {
                        q.push(now);
                        dis.push(distance+1);
                        wordDict.erase(now);
                    }
                    now[i] = rec;
                }
            }
        }
        return 0;
    }
};