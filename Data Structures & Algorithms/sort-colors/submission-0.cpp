class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;                  // where next 0 should go
        int mid = 0;                  // current element
        int high = nums.size() - 1;   // where next 2 should go

        while (mid <= high) {

            if (nums[mid] == 0) {

                swap(nums[low], nums[mid]);

                low++;
                mid++;
            }
            else if (nums[mid] == 1) {

                mid++;
            }

            else {

                swap(nums[mid], nums[high]);

                high--;

                
            }
        }
    }
};