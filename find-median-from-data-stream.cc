class MedianFinder {
  public:
    /** initialize your data structure here. */

    priority_queue<double> small;
    priority_queue<double, std::vector<double>, std::greater<double> > large;
    MedianFinder() {

    }

    void addNum(int num) {
      double dnum = num * 1.0;
      small.push(dnum);
      double tmp = small.top(); small.pop();
      large.push(tmp);

      tmp = large.top(); large.pop();
      small.push(tmp);


      if(small.size() > large.size() + 1) {
        double tmp = small.top(); small.pop();
        large.push(tmp);
      }
    }

    double findMedian() {
      if(small.size() > large.size()) {
        return small.top();
      } else {
        return (small.top() + large.top()) / 2.0;
      }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
