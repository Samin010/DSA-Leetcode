class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n = q.size();
        vector<int> ans(n, 0);
        map<int, int> hash1;
        map<int,int>hash2;
        int i = 0;
        for (auto it : q) {
            int ball = it[0];
            int color = it[1];
            // If this ball has already been colored
            if(hash1.find(ball)!=hash1.end()){
                int prev_color=hash1[ball];
                hash2[prev_color]--;
                if(hash2[prev_color]==0){
                    hash2.erase(prev_color);
                }
            }
            hash1[ball]=color;
            hash2[color]++;
            ans[i++]=hash2.size();
        }
        return ans;
    }
};