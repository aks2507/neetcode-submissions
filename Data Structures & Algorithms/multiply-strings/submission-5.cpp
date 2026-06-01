class Solution {
public:
    // This function assumes num1 has greater length than n2
    string add(string num1, string num2) {
        int carry = 0;
        int n1 = num1.length();
        int n2 = num2.length();
        string res = "";

        while(n2 > 0 || n1 > 0) {
            int sum = carry;
            if(n1 > 0) {
                sum += num1[n1 - 1] - '0';
            }
            if(n2 > 0) {
                sum += num2[n2 - 1] - '0';
            }
            // cout << "Sum = " << sum << endl;
            if (sum >= 10) {
                carry = sum / 10;
                sum = sum % 10;
            } else {
                carry = 0;
            }

            char s = sum + '0';
            res = s + res;
            n1--;
            n2--;
        }

        if (carry > 0) {
            char c = carry + '0';
            res = c + res;
        }
        return res;
    }

    string singleMultiply(string num1, char num2) {
        int n = num1.length();
        int carry = 0;
        string res = "";
        int n2 = num2 - '0';
        while(n > 0) {
            int prod = carry + ((num1[n - 1] - '0') * n2);
            if (prod >= 10) {
                carry = prod / 10;
                prod = prod % 10;
            } else {
                carry = 0;
            }
            char p = prod + '0';
            res = p + res;
            n--;
        }

        if(carry > 0) {
            char c = carry + '0';
            res = c + res;
        }

        return res;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        if (num1 == "1") {
            return num2;
        }

        if(num2 == "1") {
            return num1;
        }

        string res = "";
        int n2 = num2.length();
        string mul = singleMultiply(num1, num2[n2 - 1]);
        for (int i = num2.length() - 2; i >= 0; i--) {
            string m = singleMultiply(num1, num2[i]);
            int zeros = num2.length() - i - 1;
            while(zeros > 0) {
                m = m + '0';
                zeros--;
            }
            mul = add(m, mul);
        }

        return mul;
    }
};
