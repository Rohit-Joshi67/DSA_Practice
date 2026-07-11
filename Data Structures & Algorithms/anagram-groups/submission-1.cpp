class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        // Visit every word
        for (string word : strs) {

            // Create the signature
            string key = word;
            sort(key.begin(), key.end());

            // Store original word
            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        // Collect all groups
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};