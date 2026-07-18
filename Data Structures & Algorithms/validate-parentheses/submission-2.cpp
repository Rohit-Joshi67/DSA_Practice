class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s) {

            // opening brackets
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }

            // closing brackets
            else {

                // stack empty OR not matching
                if(
                    st.empty() ||
                    (c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')
                ) {
                    return false;
                }

                st.pop();
            }
        }

        // all brackets matched
        return st.empty();
    }
};