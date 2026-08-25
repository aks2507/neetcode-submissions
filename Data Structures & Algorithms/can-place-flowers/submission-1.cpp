class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0, sz = flowerbed.size();
        for (int i = 0; i < sz; i++) {
            if ((i - 1 >= 0 && i + 1 < sz && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 && flowerbed[i] == 0) ||
                (i - 1 < 0 && i + 1 < sz && flowerbed[i + 1] == 0 && flowerbed[i] == 0) || 
                (i - 1 >= 0 && i + 1 >= sz && flowerbed[i - 1] == 0 && flowerbed[i] == 0) ||
                (i -1 < 0 && i + 1 >= sz && flowerbed[i] == 0)
            ) {
                flowerbed[i] = 1;
                sum++;
            }
        }

        // for (int i = 0; i < sz; i++) {
        //     cout << flowerbed[i] << ", ";
        // }
        // cout << endl << "Sum = " << sum << endl;

        return sum >= n ? true : false;
    }
};