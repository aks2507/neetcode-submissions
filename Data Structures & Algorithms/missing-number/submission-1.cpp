class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int sum  = (n * (n + 1)) / 2;

        // for(int i = 0; i < n; i++) {
        //     sum = sum - nums[i]; 
        // }

        // return sum;

        // XOR
        int xorr = n;
        for(int i = 0; i < n; i++) {
            xorr = xorr ^ i ^ nums[i];
        }

        return xorr;
    }
};
