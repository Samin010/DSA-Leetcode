class Solution {
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            freq[nums[i]]++;
        vector<pair<int, int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), comp);
        vector<int> ans;
        for (auto it : vec) {
            ans.push_back(it.first);
            k--;
            if (k == 0)
                break;
        }
        return ans;
    }
};