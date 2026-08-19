class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n1; i++) {
            mp[nums1[i]] = i;
        }

        vector<int> res(n1, -1);
        stack<int> st;
        for (int num2 : nums2) {
            while (!st.empty() && num2 > st.top()) {
                int top = st.top();
                st.pop();
                int idx = mp[top];
                res[idx] = num2;
            }
            if (mp.count(num2)) {
                st.push(num2);
            }
        }

        return res;
    }
};