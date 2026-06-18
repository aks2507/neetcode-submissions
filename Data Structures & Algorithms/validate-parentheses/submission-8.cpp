class Solution {
public:
    bool isValid(string s) {
        int n = s.length();

        if(n == 0) {
            return false;
        }

        int i = 0;
        stack<char> st;
        unordered_map<char, char> m = {
            {'}', '{'},
            {')','('},
            {']', '['}
        };
        while(i < n) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == m[s[i]]) {
                    st.pop();
                } else {
                    return false;
                }                
            }

            i++;
        }

        return st.empty();
    }
};
