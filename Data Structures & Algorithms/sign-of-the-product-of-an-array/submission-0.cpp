class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negs = 0;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                negs++;
            } else if (nums[i] == 0) {
                zero = true;
            }
        }

        return zero ? 0 : (negs % 2 == 0) ? 1 : -1;
    }
};