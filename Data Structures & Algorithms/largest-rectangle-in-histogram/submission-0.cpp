class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> st;      // Stack me hum indices store karenge
        int maxArea = 0;

        // Last me ek 0 add kar diya taki stack ke saare remaining elements process ho jaye
        heights.push_back(0);

        // Har bar ko ek baar visit karenge
        for (int i = 0; i < heights.size(); i++) {

            // Jab current height stack ki top height se chhoti ho
            // Matlab top wali bar yahi tak extend kar sakti hai
            while (!st.empty() && heights[st.top()] > heights[i]) {

                // Rectangle ki height = stack ki top height
                int height = heights[st.top()];
                st.pop();

                int width;

                // Agar stack empty ho gaya
                // Matlab ye height sabse left (index 0) tak extend kar sakti thi
                if (st.empty()) {
                    width = i;
                }

                // Nahi to
                // Left boundary = stack ka naya top
                // Right boundary = current index i
                // Width = beech ke elements
                else {
                    width = i - st.top() - 1;
                }

                // Area nikal lo
                int area = height * width;

                // Maximum update karo
                maxArea = max(maxArea, area);
            }

            // Current index ko stack me daal do
            st.push(i);
        }

        return maxArea;
    }
};