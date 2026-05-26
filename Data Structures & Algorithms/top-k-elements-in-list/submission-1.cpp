class Solution {
public:
        vector<int>topKFrequent(vector<int>&nums,int k)
        {
            unordered_map<int,int>count; //map to store counts
            vector<vector<int>>freq(nums.size()+1); // vector to store freq
            for(auto n:nums)
            {
                count[n]=1+count[n]; //counting the freuency
                            }
            for(const auto &entry:count)
            {
                freq[entry.second].push_back(entry.first);  //entry  first into bucket freq first
            }
            vector<int>res;
            for(int i=freq.size()-1;i>0;--i) // reverse taversing the freq bucket 
            {
                for(int n:freq[i])              
                {
                    res.push_back(n);           //pushback the number into result 
                    if(res.size()==k)           /// until the k meets
                    return res;
                }
            }
            return res;
        }
        
};