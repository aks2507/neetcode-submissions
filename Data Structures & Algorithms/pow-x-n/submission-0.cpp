class Solution {
public:
    double myPowRec(double x, int n) {
        if (x == 1 || n == 0) {
            return 1;
        }

        if(x == 0) {
            return 0;
        }

        double sq = myPow(x, n / 2) * myPow(x, n / 2);
        return (n % 2 == 0) ? sq : sq * x;
    }
    
    double myPow(double x, int n) {
        return (n > 0) ? myPowRec(x, n) : (1 / myPowRec(x, abs(n)));
    }
};
