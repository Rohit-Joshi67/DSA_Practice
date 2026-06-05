class Solution {
public:

    int pick(vector<int>& nums, int index,vector<int> & dp)
    {
        if(index >= nums.size())
            return 0;
            if(dp[index]!=-1) //bro check if the already there
            return dp[index];

        int take = nums[index] + pick(nums, index + 2,dp);

        int skip = pick(nums, index + 1,dp);

        return dp[index]=max(take, skip);
    }

    int rob(vector<int>& nums) {
          vector<int> dp(nums.size() + 2, -1);
        return pick(nums, 0,dp);
    }
};