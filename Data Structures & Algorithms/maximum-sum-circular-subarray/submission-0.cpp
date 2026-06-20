class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int currMax=nums[0];
        int maxSum=nums[0];
        int currMin=nums[0];
        int minSum=nums[0];

        for(int x: nums)
        {
            total+=x;
        }
        for(int i=1;i<nums.size();i++)
        {
           currMax = max(nums[i], currMax + nums[i]);
            maxSum= max(maxSum,currMax);

            currMin= min(nums[i],currMin+nums[i]);
            minSum= min(currMin,minSum);
        }
        if(maxSum<0)
        return maxSum; 
        return max(maxSum,total-minSum);
    }
};