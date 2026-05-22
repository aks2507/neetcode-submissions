class Solution {
public:
    int squares(int n) {
        int res = 0;
        while(n > 0) {
            int r = n % 10;
            res += r * r;
            n = n / 10;
        }

        return res;
    }
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }
        unordered_set<int> m;
        while(1) {
            n = squares(n);
            if (m.find(n) != m.end()) {
                return false;
            } else {
                m.insert(n);
            }
            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};
