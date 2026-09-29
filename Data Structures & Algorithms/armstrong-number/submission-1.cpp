class Solution {
public:
    bool isArmstrong(int n) {
        int sum = 0;
        int curr = n;
        int exp = 0;
        while (curr) {
            exp++;
            curr /= 10;
        }
        curr = n;
        while(curr) {
            int digit = curr % 10;
            curr = curr / 10;
            sum += pow(digit, exp);
            if (sum > n) break;
        }
        // cout<< sum;
        return sum == n;
    }
};
