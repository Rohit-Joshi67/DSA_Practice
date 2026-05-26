class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for( const string& s : strs)
        {
            ans+=to_string(s.size())+"#"+s;  // convert to string of with size of string and  # and string
        }
        return ans;

    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        while(i<s.size()) //this loop will iterate till end
        {
            int j=i;
            while(s[j]!='#')    //this loop itterates till we get a #
            {
                j++;
            }
          int length = stoi(s.substr(i,j-i)); //lenght = strinng to integer of a substring made of ith and jth 
          i=j+1;                            //increase i to the place where # is 
          j=i+length;                       // j will now point end of the string 
          ans.push_back(s.substr(i,length));    // will pushback the substring of i th index and length 
          i=j;                             // now will shift i to j 
        }
    return ans;
    }
};
