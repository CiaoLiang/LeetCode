class Solution {
    struct  vertice{
        int index;
        unordered_set<int> adj;
        vertice(int a):index(a){}
    };
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret;
        if(edges.size()==0){
            ret.push_back(0);
            return ret; //1个节点的特殊情况
        }
        vector<vertice> Vertices;
        for(int i=0; i<n; ++i){
            vertice a(i);
            Vertices.push_back(a);
        }
        
        for(auto i=edges.begin(); i!=edges.end(); ++i){
            Vertices[i->first].adj.insert(i->second);
            Vertices[i->second].adj.insert(i->first); //记录图的数据
        }
        
        vector<vertice> leavel;
        for(int i=0; i<n; ++i){
            if(Vertices[i].adj.size()==1)
                leavel.push_back(Vertices[i]);//第一层节点
        }
        
        while(n>2){
            n -= leavel.size();
            vector<vertice> temp;
            for(int i=0; i<leavel.size(); ++i){
              int root = *(leavel[i].adj.begin()); //找到根节点
              Vertices[root].adj.erase(leavel[i].index);//去除子节点
              if(Vertices[root].adj.size()==1) //如果度数为1，记录新的一层
                temp.push_back(Vertices[root]);
            }
            leavel = temp;
        }
        
        for(int i=0; i<leavel.size(); ++i ){
            ret.push_back(leavel[i].index); //结果输出
        }
        return ret;
    }
};