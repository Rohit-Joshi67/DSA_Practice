class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int end=n-1;
        int area=0;
        int cur;
        int i=0;
        int maxarea=0;
        while(i<end)
        {
            if(heights[i]>heights[end])
            {
                area=(min(heights[i],heights[end])*(end-i));
                end--;
                
            }
            else 
            {
                area=(min(heights[i],heights[end])*(end-i));
                i++;
            }
            maxarea=max(maxarea,area);
        }
        return maxarea;
    }
};
