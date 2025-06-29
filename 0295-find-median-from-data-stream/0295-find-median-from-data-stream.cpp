class MedianFinder {
public:
   priority_queue<int,vector<int>,greater<int>> minHeap;
   priority_queue<int> maxHeap;
   double median;
    MedianFinder() {
       median =0; 
    }
    
    void addNum(int num) {
        if(minHeap.size()==maxHeap.size()){
            if(num>median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                maxHeap.push(num);
                median=maxHeap.top();
            }
        }
        else if(minHeap.size()==maxHeap.size()+1){
            if(num>median){
                int val=minHeap.top();
                minHeap.pop();
                maxHeap.push(val);
                minHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                maxHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
        else if(minHeap.size()+1==maxHeap.size()){
            if(num>median){
                minHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                int val=maxHeap.top();
                maxHeap.pop();
                minHeap.push(val);
                maxHeap.push(num);
                median= (minHeap.top()+maxHeap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */