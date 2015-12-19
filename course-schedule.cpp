class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> V(numCourses);
        for(int i=0; i<prerequisites.size(); ++i){
            V[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<bool> marked(numCourses,false);
        vector<bool> onstack(numCourses,false);
        bool cycle = false;
        for(int i=0; i<numCourses; ++i){
            if(!marked[i])
                dfs(V,i,marked,onstack,cycle);//DFS
        }
        return !cycle;
    }
    void dfs(vector<vector<int>> &V,int Vindex,vector<bool> &marked,vector<bool> &onstack,bool &cycle){
        onstack[Vindex] = true;//stack
        marked[Vindex] = true;//marked 
        for(int i=0; i<V[Vindex].size(); ++i){
            if(cycle == true)
                return;
            int w = V[Vindex][i];
            if(!marked[w]){
                dfs(V,w,marked,onstack,cycle);
            }
            else if(onstack[w])
                cycle = true;
        }
        onstack[Vindex] = false;
    }
};