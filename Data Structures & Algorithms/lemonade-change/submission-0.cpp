class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        if (bills[0] != 5) {
            return false;
        }
        int bills5 = 1;
        int bills10 = 0;
        for (int i = 1; i < n; i++) {
            if (bills[i] == 5) {
                bills5++;
            } else if(bills[i] == 10) {
                bills5--;
                bills10++;
            } else if (bills10 > 0) {
                bills5--;
                bills10--;
            } else {
                bills5 -= 3;
            }

            if (bills5 < 0) {
                return false;
            }
        }

        return true;
    }
};