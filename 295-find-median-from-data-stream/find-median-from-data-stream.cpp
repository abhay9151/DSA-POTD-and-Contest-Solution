class MedianFinder {
    vector<int>arr;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int low = 0;
        int high = arr.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] < num)
                low = mid + 1;
            else
                high = mid;
        }
        arr.insert(arr.begin() + low, num);
    }
    
    double findMedian() {
        int n=arr.size();
        if(n%2==1)return arr[n/2];
        else{
            return (arr[n/2]+arr[n/2-1])/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */