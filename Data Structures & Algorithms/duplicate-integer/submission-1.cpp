class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
      int n= nums.size();
      sort(nums.begin(), nums.end());
      int right =1;
      while(right<n)
      {
          int left = right - 1;
          if(nums[left]==nums[right])
          {
              return true;
          }
          else
          {
              right++;
          }
      }
      return false;
    }
};