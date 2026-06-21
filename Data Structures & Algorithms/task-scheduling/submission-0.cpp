class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int> freq(26, 0);
        for(auto& task: tasks) {
            freq[task - 'A']++;
        } 
        queue<pair<int, int>> cooldownQueue;
        priority_queue<int> remainingCount;

        for(auto& count: freq) {
            if(count > 0) {
                remainingCount.push(count);
            }
        }

        while(!remainingCount.empty() || !cooldownQueue.empty()) {
            time++;

            if (remainingCount.empty()) {
                time = cooldownQueue.front().second;
            } else {
                int count = remainingCount.top() - 1;
                remainingCount.pop();
                if(count > 0) {
                    cooldownQueue.push({count, time + n});
                }
            }

            if(!cooldownQueue.empty() && cooldownQueue.front().second == time) {
                remainingCount.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return time;
    }
};
