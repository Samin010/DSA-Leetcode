class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(x || y){
            int i=x&1;
            int j=y&1;
            ans+=(i^j);
            x=x>>1;
            y=y>>1;
        }
        return ans;
    }
};