class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prefix =1;
        int suffix=1;
        vector<int>product(n,1);
        for(int i=0;i<n;i++) {
            product[i] = prefix;
            prefix*=nums[i];   
        }

        for(int i=n-1;i>=0;i--) {
            product[i]*=suffix;   
            suffix*=nums[i];
        }
        return product;
    }
};
