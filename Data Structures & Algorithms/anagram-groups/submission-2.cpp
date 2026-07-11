class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string word : strs) {

            // Count frequency of each character
            vector<int> freq(26, 0);

            for (char ch : word) {
                freq[ch - 'a']++;
            }

            // Create a unique signature
            string key = "";

            for (int count : freq) {
                key += "#" + to_string(count);
            }

            // Group the original word
            mp[key].push_back(word);
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};