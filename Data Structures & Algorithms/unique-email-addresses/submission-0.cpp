class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (string email : emails) {
            string local = email.substr(0, email.find('@'));

            local = local.substr(0, local.find('+'));

            local.erase(remove(local.begin(), local.end(), '.'), local.end());

            st.insert(local + email.substr(email.find('@')));
        }

        return st.size();
    }
};