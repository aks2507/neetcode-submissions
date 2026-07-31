class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int finalShift = 0;

        for (int i = 0; i < shift.size(); i++) {
            vector<int> vec = shift[i];
            if (vec[0] == 0) {
                finalShift -= vec[1];
            } else {
                finalShift += vec[1];
            }
        }

        if (finalShift == 0) {
            return s;
        }

        bool left = finalShift < 0;
        int n = s.length();
        finalShift = (abs(finalShift)) % n;

        // cout << finalShift << " and " << left << endl;

        if (left) {
            s = s.substr(finalShift) + s.substr(0, finalShift);
        } else {
            // cout << "here"<<endl;
            s = s.substr(n - finalShift, finalShift) + s.substr(0, n - finalShift);
        }

        return s;
    }
};
