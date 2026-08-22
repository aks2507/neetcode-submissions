class MovingAverage {
private:
    int sum = 0;
    queue<int> q;
    int currSize = 0;
    int maxSize = 0;
public:
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        if (currSize < maxSize) {
            q.push(val);
            sum += val;
            currSize++;
        } else if (currSize == maxSize) {
            int front = q.front();
            q.pop();
            q.push(val);
            sum = sum - front + val;
        }

        return (double) sum / currSize;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
