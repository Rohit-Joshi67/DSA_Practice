class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;           // skip already used elements

            path.push_back(nums[i]);         // choose
            used[i] = true;
            backtrack(nums, used, path);     // explore
            path.pop_back();                 // un-choose
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path);
        return result;
    }
};