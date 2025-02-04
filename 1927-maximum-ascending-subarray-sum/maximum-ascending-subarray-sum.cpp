class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int val=0;
        int prev=-1;
        for(int i=0;i<n;i++){
             if(prev==-1 || nums[i]>prev){
                val+=nums[i];
             }
             else val=nums[i];
             ans=max(ans,val);
             prev=nums[i];
        }
        return ans;
    }
};