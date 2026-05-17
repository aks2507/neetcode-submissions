class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        int i = 0;

        unordered_map<char, char> paranthesis_mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        while(i < s.size()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i++]);
            } else {
                if (st.empty()) {
                    return false;
                } else if (st.top() != paranthesis_mapping[s[i++]]) {
                    return false;
                }

                st.pop();
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};
