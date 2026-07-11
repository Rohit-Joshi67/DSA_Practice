class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        return false;
       int f[26]={0};

       for(char c :s){
        f[c-'a']++;
        
       }

       for(char c: t) {
        f[c -'a']--;
       }

       for(int count :f) {
        if(count!=0)
        return false;
       }
       return true;
    }
};
