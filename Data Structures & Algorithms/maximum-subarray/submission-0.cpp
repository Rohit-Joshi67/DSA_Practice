class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int bestsum =nums[0];
        for(int i=0;i<nums.size();i++)
        {
            currsum= max(nums[i],currsum+nums[i]);
            bestsum= max(bestsum,currsum);
        }
        return bestsum;
    }
};
