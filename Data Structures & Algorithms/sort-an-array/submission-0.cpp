class Solution {
private:
    void merge(int l, int mid, int r, vector<int>& arr) {
        vector<int> tmp;
        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            tmp.push_back(arr[i] <= arr[j] ? arr[i++] : arr[j++]);
        }

        while(i <= mid) {
            tmp.push_back(arr[i++]);
        }

        while(j <= r) {
            tmp.push_back(arr[j++]);
        }

        for (int i = l; i <= r; i++) {
            arr[i] = tmp[i - l];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if (l == r) {
            return;
        }

        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);

        merge(l, mid, r, arr);
    } 
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};