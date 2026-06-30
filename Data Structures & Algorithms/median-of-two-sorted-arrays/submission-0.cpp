class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1;
        vector<int> B = nums2;
        int total = A.size() + B.size();
        int half = total / 2;


        if(A.size() > B.size()) {
            swap(A, B);
        }

        int l = 0, r = A.size() - 1;
        while(true) {
            int midA = ((l + r) < 0) ? -1 : (l + r) / 2;

            int midB = half - midA - 2;

            int Aleft = (midA >= 0 ) ? A[midA] : INT_MIN;
            int Aright = (midA + 1 < A.size()) ? A[midA + 1] : INT_MAX;
            int Bleft = (midB >= 0) ? B[midB] : INT_MIN;
            int Bright = (midB + 1 < B.size()) ? B[midB + 1] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 1) {
                    return (double)min(Aright, Bright);
                } else {
                    return (double)(max(Aleft, Bleft) + min(Aright, Bright)) / 2;
                }
            } else if (Aleft > Bright) {
                r = midA - 1;
            } else {
                l = midA + 1;
            }
        }
    }
};
