class Solution {
public:

    // Expand from the center and return palindrome length
    int expand(string &s, int left, int right)
    {
        int n = s.size();

        // Keep expanding while:
        // 1. indices are valid
        // 2. characters match
        while(left >= 0 && right < n && s[left] == s[right])
        {
            left--;
            right++;
        }

        // We expanded one step extra before stopping
        return right - left - 1;
    }

    string longestPalindrome(string s) {

        int start = 0;   // starting index of longest palindrome
        int end = 0;     // ending index of longest palindrome

        for(int i = 0; i < s.size(); i++)
        {
            // Odd length palindrome
            // Example: "bab"
            int len1 = expand(s, i, i);

            // Even length palindrome
            // Example: "abba"
            int len2 = expand(s, i, i + 1);

            // Take maximum length found from this center
            int len = max(len1, len2);

            // If we found a bigger palindrome
            if(len > end - start + 1)
            {
                // Calculate new boundaries

                // For odd:
                // len=5, center=i
                // start=i-2, end=i+2

                // For even:
                // len=4, center between i and i+1
                // formula still works

                start = i - (len - 1) / 2;
                end   = i + len / 2;
            }
        }

        // Return longest palindrome substring
        return s.substr(start, end - start + 1);
    }
};