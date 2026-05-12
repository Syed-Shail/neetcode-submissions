class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> minHip;
    priority_queue<int,vector<int>,less<int>> maxHip;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHip.empty()){
            maxHip.push(num);
            return;
        }

        maxHip.push(num);
        minHip.push(maxHip.top());
        maxHip.pop();
        if(abs((int)minHip.size()-(int)maxHip.size())>1){
            if(minHip.size()>maxHip.size()){
                maxHip.push(minHip.top());
                minHip.pop();
            }
            else{
                minHip.push(maxHip.top());
                maxHip.pop();
            }
        }

    }
    
    double findMedian() {
        if(minHip.size()>maxHip.size()){
            return minHip.top();
        }
        if(maxHip.size()>minHip.size()){
            return maxHip.top();
        }
        double a = minHip.top();
        double b = maxHip.top();
        return (a+b)/2;
    }
};
