class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length() - 1, n2 = b.length() - 1;
        int carry = 0;
        string res = "";
        while (n1 >= 0 || n2 >= 0 || carry > 0) {
            int first = (n1 >= 0) ? a[n1] - '0' : 0;
            int second = (n2 >= 0) ? b[n2] - '0' : 0;

            int total = first + second + carry;
            res += (total % 2) + '0';
            carry = total / 2;

            n1--;
            n2--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};