class Solution {
public:
    
    // -1 = not computed
    //  0 = not palindrome
    //  1 = palindrome
    vector<vector<int>> dp;

    bool isPalindrome(string &s, int i, int j)
    {
        // Empty or single char string is palindrome
        if(i >= j)
            return true;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] != s[j])
            return dp[i][j] = 0;

        return dp[i][j] = isPalindrome(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {

        int n = s.size();

        dp.assign(n, vector<int>(n, -1));

        int start = 0;
        int maxLen = 1;

        // Try every substring
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                if(isPalindrome(s, i, j))
                {
                    int len = j - i + 1;

                    if(len > maxLen)
                    {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};