class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i]) != mp.end())
            return true;
            mp.insert({nums[i]});
        }
        return false;
    }   
};