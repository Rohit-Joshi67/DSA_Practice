class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0,r=nums.size()-1,l=0;;
        vector<int> temp=nums;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==0)
            {
                nums[r]=0;
                r--;
            }
            else
            {
                nums[l]=temp[i];
                l++;
            }
        }   
    }
};