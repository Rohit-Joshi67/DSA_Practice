class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        int maxRight = -1;

        for(int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];   // save original value

            arr[i] = maxRight;   // replace with greatest on right

            maxRight = max(maxRight, curr);
        }

        return arr;
    }
};