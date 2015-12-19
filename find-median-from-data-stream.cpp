class MedianFinder {
private:
    priority_queue<int> MaxHeap;
    priority_queue<int,vector<int>,greater<int> > MinHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
      MaxHeap.push(num);
      MinHeap.push(MaxHeap.top());
      MaxHeap.pop();
      if(MaxHeap.size() < MinHeap.size()){
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
     }
    }

    // Returns the median of current data stream
    double findMedian() {
        return MaxHeap.size()==MinHeap.size()?(MaxHeap.top()+MinHeap.top())/2.0:MaxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();