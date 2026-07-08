class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for (int i = 0 ; i < operations.size(); i++) {
            if (operations[i] == "C") {
                s.pop();
            } else if (operations[i] == "D") {
                int t = s.top();
                s.push(2 * t);
            } else if (operations[i] == "+") {
                int t1 = s.top();
                s.pop();
                int t2 = s.top();
                int sum = t1 + t2;
                s.push(t1);
                s.push(sum);
            } else {
                s.push(stoi(operations[i]));
            }
        }

        int res = 0;
        while(!s.empty()) {
            res += s.top();
            s.pop();
        }

        return res;
    }
};