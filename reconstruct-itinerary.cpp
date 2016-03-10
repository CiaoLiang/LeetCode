'class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,multiset<string>> Graph;
        for(int i=0; i<tickets.size(); ++i){
            Graph[tickets[i].first].insert(tickets[i].second);//构建图
        }
        vector<string> itinerary;
        vector<string> matching;//BFS
        matching.push_back("JFK");
        while(matching.size()>0){
            string from = matching.back();
            if(Graph.count(from)>0 && Graph[from].size()>0)
            {
                multiset<string>& to = Graph[from];
                matching.push_back(*to.begin());
                to.erase(to.begin());
            }
            else
            {
                itinerary.push_back(from);
                matching.pop_back();
            }
        }
        reverse(itinerary.begin(),itinerary.end());
        return itinerary;
    }
};',
  