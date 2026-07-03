class Solution {
public:
vector<vector<int>> result;
    void backtrack(vector<int>nums ,int i,vector<int> path) {
        result.push_back(path);
        for(int j=i;j<nums.size();j++){
            path.push_back(nums[j]);
            backtrack(nums,j+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(nums,0,path);
        return result;
    }
};
