class Solution {
public:
    bool isAnagram(string s, string t) {
         sort(s.begin(), s.end());
            sort(t.begin(), t.end());
       int n=s.size();
       if(n!=t.size())
       return false;
       else {
        for(int i=0;i<n;i++)
        {
            if(t[i]!=s[i])
            return false;
        }
       }
       return true;
    }
};
