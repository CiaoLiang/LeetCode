class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> V(numCourses);
        vector<int> Order;
        for(int i=0; i<prerequisites.size(); ++i){
            V[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<bool> marked(numCourses,false);
        vector<bool> onstack(numCourses,false);
        bool cycle = false;
        for(int i=0; i<numCourses; ++i){
            if(!marked[i])
                dfs(V,i,marked,onstack,cycle,Order);//DFS
        }
        if(cycle == true)
            return vector<int>(0);
        else{
            return Order;
        }
        return Order;
    }
    void dfs(vector<vector<int>> &V,int Vindex,vector<bool> &marked,vector<bool> &onstack,bool &cycle,vector<int> &Order){
        onstack[Vindex] = true;//stack
        marked[Vindex] = true;//marked 
        for(int i=0; i<V[Vindex].size(); ++i){
            if(cycle == true)
                return;
            int w = V[Vindex][i];
            if(!marked[w]){
                dfs(V,w,marked,onstack,cycle,Order);
            }
            else if(onstack[w])
                cycle = true;
        }
        Order.push_back(Vindex);
        onstack[Vindex] = false;
    }
};