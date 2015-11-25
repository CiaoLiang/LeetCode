/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
         int first = newInterval.start;
         int second = newInterval.end;
         bool flag = false;
         vector<Interval> res;
         if(intervals.size()==0){
             res.push_back(newInterval);
             return res;
         }
         for(int i=0; i<intervals.size(); ++i){
             Interval temp;
             if(i!=0) temp = res.back();
             if(i!=0&&!(intervals[i].start > temp.end || intervals[i].end < temp.start)){
                 temp.end = max(temp.end,intervals[i].end);
                 temp.start = min(temp.start,intervals[i].start);
                 res.pop_back();
                 res.push_back(temp);
                 continue;
             }
             
             if(!(intervals[i].start > second || intervals[i].end < first)){
                 intervals[i].end = max(intervals[i].end ,second);
                 intervals[i].start = min(intervals[i].start ,first);
                 flag = true;
             }
             
             res.push_back(intervals[i]);
         }
         if(flag == false){
             if(newInterval.start>res.back().start){
                 res.push_back(newInterval);
                 return res;
             }
             for(int i=0; i<res.size(); ++i){
                 if(newInterval.start<res[i].start){
                     res.insert(res.begin()+i,newInterval);
                     break;
                 }
             }
         }
         
         return res;
    }
};