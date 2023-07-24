class MedianFinder {
    priority_queue<int> arr1;
    priority_queue<int, vector<int>, greater<int>> arr2;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(arr1.empty() || arr1.top() >= num) arr1.push(num);
        else arr2.push(num);

        if(arr1.size() > arr2.size() + 1){
            arr2.push(arr1.top());
            arr1.pop();
        }
        else if(arr1.size() < arr2.size()){
            arr1.push(arr2.top());
            arr2.pop();
        }
    }
    
    double findMedian() {
        if(arr1.size() == arr2.size()){
            return double((arr1.top() + arr2.top())/2.0);
        }
        else{
            return double(arr1.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */