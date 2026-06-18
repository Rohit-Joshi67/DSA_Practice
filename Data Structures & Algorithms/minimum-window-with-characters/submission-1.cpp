class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;    // what we need from t
        unordered_map<char, int> window;  // what current window has

        // Count required characters
        // Example: t = "AABC"
        // need = {A:2, B:1, C:1}
        for (char c : t)
            need[c]++;

        int have = 0;              // requirements satisfied till now
        int totalNeed = need.size(); // unique chars needed

        int l = 0;                 // left pointer
        int minLen = INT_MAX;      // best answer length
        int start = 0;             // best answer start index

        // Expand window using right pointer
        for (int r = 0; r < s.size(); r++) {

            char c = s[r];

            // Add current char into window
            window[c]++;

            // If this char's required frequency is reached
            // Example:
            // need[A]=2 and window[A]=2
            if (need.count(c) && window[c] == need[c])
                have++;

            // If all requirements are satisfied
            while (have == totalNeed) {

                // Save smaller answer
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // Remove left character
                char leftChar = s[l];
                window[leftChar]--;

                // If requirement breaks after removal
                // Example:
                // need[A]=2
                // window[A] becomes 1
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar])
                    have--;

                // Shrink window
                l++;
            }
        }

        // No valid window found
        if (minLen == INT_MAX)
            return "";

        // Return smallest valid substring
        return s.substr(start, minLen);
    }
};