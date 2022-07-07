//Using balanced binary tree (multiset) method
//TC:O(logn)
//SC:O(n)
class MedianFinder {
    multiset<int> data;
    multiset<int>::iterator mid;
public:
    MedianFinder()
        : mid(data.end())
    {
    }
    void addNum(int num)
    {
        const int n = data.size();
        data.insert(num);
        // first element inserted
        if (!n)                                 
            mid = data.begin();
        // maintain mid at the right of median components
        // median is decreased
        else if (num < *mid)                    
            mid = (n & 1 ? mid : prev(mid));
        // median is decreased
        else                                    
            mid = (n & 1 ? next(mid) : mid);
    }
    double findMedian()
    {
        const int n = data.size();
        cout << *next(mid, n % 2 - 1) << endl;
        return (*mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};