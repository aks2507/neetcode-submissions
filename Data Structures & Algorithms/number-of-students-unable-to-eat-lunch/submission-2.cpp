class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // queue<pair<int, int>> q;
        // stack<int> st;
        // for (int i = 0; i < students.size(); i++) {
        //     q.push({i, students[i]});
        // }

        // for (int i = sandwiches.size() - 1; i >= 0; i--) {
        //     st.push(sandwiches[i]);
        // }

        // int rotated = 0;

        // while (q.size() > 0 && rotated < q.size()) {
        //     auto student = q.front();
        //     q.pop();

        //     auto sandwich = st.top();
        //     if (sandwich == student.second) {
        //         st.pop();
        //         rotated = 0;
        //     } else {
        //         rotated++;
        //         q.push(student);
        //     }
        // }

        // return q.size();

        vector<int> count(2, 0);

        for (int student : students) {
            count[student]++;
        }

        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0) {
                return count[0] + count[1];
            }

            count[sandwich]--;
        }

        return 0;
    }
};