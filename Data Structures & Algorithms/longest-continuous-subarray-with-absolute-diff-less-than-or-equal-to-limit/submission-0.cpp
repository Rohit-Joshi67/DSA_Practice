class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> maxD; // decreasing
        deque<int> minD; // increasing

        int l = 0;
        int ans = 0;

        for (int r = 0; r < nums.size(); r++) {

            // Maintain max deque
            while (!maxD.empty() && maxD.back() < nums[r])
                maxD.pop_back();

            maxD.push_back(nums[r]);

            // Maintain min deque
            while (!minD.empty() && minD.back() > nums[r])
                minD.pop_back();

            minD.push_back(nums[r]);

            // Window invalid
            while (maxD.front() - minD.front() > limit) {

                // remove left element if it is max
                if (nums[l] == maxD.front())
                    maxD.pop_front();

                // remove left element if it is min
                if (nums[l] == minD.front())
                    minD.pop_front();

                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};