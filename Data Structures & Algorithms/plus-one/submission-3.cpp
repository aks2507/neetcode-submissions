class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = (digits[n - 1] + 1) == 10 ? 1 : 0;
        digits[n - 1] = (digits[n - 1] + 1) % 10;
        for(int i = n - 2; i >= 0; i--) {            
            int num = digits[i] + carry;
            if (num == 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            num = num % 10;
            digits[i] = num;
        }

        if (carry && digits[0] == 0) {
            digits.push_back(-1);
            for(int i = n; i >0; i--) {
                digits[i] = digits[i - 1];
            }

            digits[0] = carry;
        }

        return digits;
    }
};
