class Solution {
public:
vector<vector<int>>ans;
    void dfs(vector<int>& nums, int target,int index,vector<int> temp)
    {       
        if(target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(target<0 || index>=nums.size())
        {
            return ;
        }
            temp.push_back(nums[index]);
            dfs(nums,target-nums[index],index,temp);
            temp.pop_back();
            dfs(nums,target,++index,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
     vector<int>temp;
     dfs(nums,target,0,temp); 
     return ans;  
    }
};
