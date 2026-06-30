class MedianFinder {
public:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        if (lower.size() > upper.size() + 1)
        {
            upper.push(lower.top());
            lower.pop();
        }

        if (upper.size() > lower.size() + 1)
        {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (upper.size() > lower.size())        return upper.top();
        else if (lower.size() > upper.size())   return lower.top();
        else                                    return (upper.top() + lower.top()) / 2.0;        
    }
};
