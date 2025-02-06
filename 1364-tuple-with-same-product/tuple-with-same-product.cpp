class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        // Map to calculate ferquencies of distinct Products
        map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int val = nums[i] * nums[j];
                freq[val]++;
            }
        }
        // We have 4 places to fll _*_=_*_  first place can be filled by freq*2(
        // because freq[i] is the no. of pairs) second place has only one choice
        // because we have o choose from the given pair. Similarly 3rd place has
        // freq[i]*2-2 & 4th place has only one choice

        long long ans = 0;
        for (auto it : freq) {
            if (it.second >= 2) {
                int first_place = it.second * 2;
                int third_place = it.second * 2 - 2;
                ans += (first_place * third_place);
            }
        }
        return int(ans);
    }
};